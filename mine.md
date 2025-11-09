# 1 整体结构设计
## 1.1 分层设计
```
┌─────────────────────────────┐
│   UI Layer                  │ ← 显示界面、获取输入
├─────────────────────────────┤
│   Logic Layer               │ ← 游戏规则、状态管理
├─────────────────────────────┤
│   Data Layer                │ ← 棋盘数据、游戏状态
└─────────────────────────────┘
```
## 1.2 模块划分
- 数据结构模块：定义游戏状态
- 游戏逻辑模块：实现核心算法
- 界面显示模块：用户交互及游戏界面显示
- 主控制模块：游戏流程控制
# 2 核心数据结构
## 2.1 游戏状态结构体
```c
typedef struct {
    int rows, cols;           // 棋盘尺寸
    int mines;                // 地雷总数
    int mines_left;           // 剩余未标记地雷数
    int cells_left;           // 剩余未翻开格子数
    char board[ROWS][COLS];   // 玩家可见棋盘
    char mines_map[ROWS][COLS]; // 真实地雷分布
    int game_over;            // 游戏结束标志
    int game_won;             // 游戏胜利标志
} Game;
```
## 2.2 双棋盘设计
- 便于调试及作弊功能的实现
- 方便判断游戏状态

| 棋盘          | 用途   | 内容                         |
| ----------- | ---- | -------------------------- |
| `board`     | 玩家可见 | `#`未翻开、`F`标记、`*`地雷、`0-8`数字 |
| `mines_map` | 真实分布 | `*`地雷、`0-8`周围地雷数           |
# 3 核心算法设计
## 3.1 地雷布置算法
- 第一次点击必定安全(不会踩雷)
- 第一次点击周围8格不放雷
- 布雷同时计算周围地雷数(一次遍历完成)
```c file:随机布置地雷
void place_mines(Game *game, int first_row, int first_col) {
    srand(time(NULL));
    int mines_placed = 0;
    
    while (mines_placed < game->mines) {
        int row = rand() % game->rows;
        int col = rand() % game->cols;
        
        // 不在第一次点击的位置及其周围放地雷
        if (game->mines_map[row][col] != '*' &&
            !(row >= first_row - 1 && row <= first_row + 1 &&
              col >= first_col - 1 && col <= first_col + 1)) {
            
            // 放置地雷
            game->mines_map[row][col] = '*';
            mines_placed++;
            
            // 立即更新周围8个格子的地雷计数
            // 这样只需要遍历地雷数量次，而不是所有格子
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // 跳过地雷本身
                    
                    int ni = row + di;
                    int nj = col + dj;
                    
                    // 检查边界并更新非地雷格子
                    if (ni >= 0 && ni < game->rows && 
                        nj >= 0 && nj < game->cols && 
                        game->mines_map[ni][nj] != '*') {
                        game->mines_map[ni][nj]++;
                    }
                }
            }
        }
    }
}
```
## 3.2 翻开空白区域算法
### 3.2.1 "洪水填充"算法
- 一种图形算法，模拟"水流扩散"的过程
    - 从一个起点开始
    - 向四周(或八个方向)蔓延
    - 填充所有相连的区域
    - 直到遇到边界或不同颜色为止
#### 在扫雷游戏中的应用
- **起点**：玩家点击的空白格(周围无雷)
- **扩散规则**：只在空白格('0')中扩散
- **边界**：有数字的格子(周围有雷)
- **结果**：自动翻开一大片连续的安全区域
```title:步骤1:翻开起点
# # # # #
# # # # #
# # X # #    ← 玩家点击X位置
# # # # #
# # # # #
```
```title:步骤2:向8个方向扩散
# # # # #
# 0 0 0 #    ← 上左、上、上右
# 0 0 0 #    ← 左、中心、右
# 0 0 0 #    ← 下左、下、下右
# # # # #

8个方向：
  ↖ ↑ ↗
  ← ● →
  ↙ ↓ ↘
```
```title:步骤3:从这9个格子继续向外扩散
0 0 0 0 1    ← 每个'0'都会向周围8个方向扩散
0 0 0 0 1       直到遇到数字格子停止
0 0 0 0 1
0 0 0 0 1
1 1 1 1 2
```
#### 遍历当前格子周围的8个格子
- 假设当前格子坐标是`(row,col)`, 其周围的8个格子坐标
```
(row-1, col-1)  (row-1, col)  (row-1, col+1)
(row,   col-1)  (row,   col)  (row,   col+1)
(row+1, col-1)  (row+1, col)  (row+1, col+1)
```
- 周围8个格子坐标相对于中心的偏移量
```
(-1, -1)  (-1,  0)  (-1, +1)    ← 上一行：row-1
( 0, -1)  ( 0,  0)  ( 0, +1)    ← 当前行：row
(+1, -1)  (+1,  0)  (+1, +1)    ← 下一行：row+1
   ↑         ↑         ↑
  col-1     col      col+1
```
- 以相对中心的偏移量进行循环遍历
```c
for (int di = -1; di <= 1; di++) {      // di 取值：-1, 0, 1
    for (int dj = -1; dj <= 1; dj++) {  // dj 取值：-1, 0, 1
        if (di == 0 && dj == 0) continue;  // 跳过中心(0, 0)
        reveal_empty_cells(game, row + di, col + dj);
    }
}
```
##### 执行分析

| 循环次数 | di  | dj  | 偏移量      | 实际坐标           | 方向   |
| ---- | --- | --- | -------- | -------------- | ---- |
| 1    | -1  | -1  | (-1, -1) | (row-1, col-1) | 左上 ↖ |
| 2    | -1  | 0   | (-1, 0)  | (row-1, col)   | 上 ↑  |
| 3    | -1  | 1   | (-1, 1)  | (row-1, col+1) | 右上 ↗ |
| 4    | 0   | -1  | (0, -1)  | (row, col-1)   | 左 ←  |
| 5    | 0   | 0   | (0, 0)   | (row, col)     | 跳过 ● |
| 6    | 0   | 1   | (0, 1)   | (row, col+1)   | 右 →  |
| 7    | 1   | -1  | (1, -1)  | (row+1, col-1) | 左下 ↙ |
| 8    | 1   | 0   | (1, 0)   | (row+1, col)   | 下 ↓  |
| 9    | 1   | 1   | (1, 1)   | (row+1, col+1) | 右下 ↘ |
#### 算法实现
```c file:递归翻开空白区域
void reveal_empty_cells(Game *game, int row, int col) {
    // 1. 递归终止条件（水流边界）
    if (!is_valid(game, row, col) ||          // 越界
        game->board[row][col] != '#') {       // 已翻开
        return;
    }
    
    // 2. 翻开当前格子（填充当前位置）
    game->board[row][col] = game->mines_map[row][col];
    game->cells_left--;
    
    // 3. 决定是否继续扩散
    if (game->mines_map[row][col] == '0') {    // 只有空白格继续扩散
        // 4. 向8个方向递归（水流向周围扩散）
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) continue;  // 跳过自己
                reveal_empty_cells(game, row + di, col + dj);
            }
        }
    }
}
```
## 3.3 胜负判定
```c file:胜利条件
cells_left == 0 //所有非地雷格子都已翻开
```

```file:失败判定逻辑
1. 玩家选择操作 1（翻开格子）
2. 输入有效坐标 (row, col)
3. 该格子未被标记（不是 'F'）
4. 执行 reveal_cell(game, row, col)
5. 检查真实地雷图：game->mines_map[row][col] == '*'
6. 条件成立 → 设置 game->game_over = 1
```
# 4 界面设计
``` file:游戏界面
==== 扫雷游戏 ====
剩余地雷数: 10
剩余格子数: 71

     0  1  2  3  4  5  6  7  8 
   +---------------------------
 0 | #  #  #  #  #  #  #  #  #  
 1 | #  #  #  #  #  #  #  #  #  
 2 | #  #  #  #  #  #  #  #  #  
 3 | #  #  #  #  #  #  #  #  #  
 4 | #  #  #  #  #  #  #  #  #  
 5 | #  #  #  #  #  #  #  #  #  
 6 | #  #  #  #  #  #  #  #  #  
 7 | #  #  #  #  #  #  #  #  #  
 8 | #  #  #  #  #  #  #  #  #  

操作说明:
  1 - 翻开格子
  2 - 标记/取消标记
  3 - 查看地雷布局（作弊模式）
  0 - 退出游戏

请选择操作 (1-翻开, 2-标记, 3-查看地雷, 0-退出): 
```

``` file:符号含义
# - 未翻开
F - 玩家标记
* - 地雷（游戏结束时显示）
数字 - 周围地雷数
空格 - 周围无地雷
```

```file:用户交互流程
1. 选择操作（翻开/标记/查看地雷/退出）
2. 输入坐标（行号、列号）
3. 执行操作
4. 更新界面
5. 检查游戏状态
6. 返回步骤1或结束
```
# 5 游戏流程
```
start
    ↓
init board
    ↓
show board  ←───────┐
    ↓               │
get user input      │
    ↓               │
first click?        │
  yes → place mines │
  no ↓              │
exec op             │
    ↓               │
update board        │
    ↓               │
isWin?              │
  no ───────────────┘
 yes ↓
show info
    ↓
game over
```
# 6 完整实现
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

// ==================== 游戏配置 ====================
#define ROWS 9
#define COLS 9
#define MINES 10

// ==================== 数据结构 ====================
typedef struct {
    int rows;
    int cols;
    int mines;
    int mines_left;
    int cells_left;
    char board[ROWS][COLS];      // 显示给玩家的棋盘
    char mines_map[ROWS][COLS];  // 真实的地雷分布（'*'表示地雷，数字表示周围地雷数）
    int game_over;
    int game_won;
} Game;

// ==================== 游戏逻辑函数 ====================

// 初始化游戏
void init_game(Game *game) {
    game->rows = ROWS;
    game->cols = COLS;
    game->mines = MINES;
    game->mines_left = MINES;
    game->cells_left = ROWS * COLS - MINES;
    game->game_over = 0;
    game->game_won = 0;
    
    // 初始化棋盘（全部未翻开，显示为'#'）
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game->board[i][j] = '#';
            game->mines_map[i][j] = '0';
        }
    }
}

// 随机布置地雷（优化版：布雷时立即更新周围计数）
void place_mines(Game *game, int first_row, int first_col) {
    srand(time(NULL));
    int mines_placed = 0;
    
    while (mines_placed < game->mines) {
        int row = rand() % game->rows;
        int col = rand() % game->cols;
        
        // 不在第一次点击的位置及其周围放地雷
        if (game->mines_map[row][col] != '*' &&
            !(row >= first_row - 1 && row <= first_row + 1 &&
              col >= first_col - 1 && col <= first_col + 1)) {
            
            // 放置地雷
            game->mines_map[row][col] = '*';
            mines_placed++;
            
            // 立即更新周围8个格子的地雷计数
            // 这样只需要遍历地雷数量次，而不是所有格子
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // 跳过地雷本身
                    
                    int ni = row + di;
                    int nj = col + dj;
                    
                    // 检查边界并更新非地雷格子
                    if (ni >= 0 && ni < game->rows && 
                        nj >= 0 && nj < game->cols && 
                        game->mines_map[ni][nj] != '*') {
                        game->mines_map[ni][nj]++;
                    }
                }
            }
        }
    }
}

// 检查坐标是否有效
int is_valid(Game *game, int row, int col) {
    return row >= 0 && row < game->rows && col >= 0 && col < game->cols;
}

// 递归翻开空白区域
void reveal_empty_cells(Game *game, int row, int col) {
    if (!is_valid(game, row, col) || game->board[row][col] != '#') {
        return;
    }
    
    game->board[row][col] = game->mines_map[row][col];
    game->cells_left--;
    
    // 如果是空白格（周围没有地雷），递归翻开周围格子
    if (game->mines_map[row][col] == '0') {
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) continue;
                reveal_empty_cells(game, row + di, col + dj);
            }
        }
    }
}

// 翻开一个格子
void reveal_cell(Game *game, int row, int col) {
    if (!is_valid(game, row, col)) {
        return;
    }
    
    if (game->board[row][col] != '#' && game->board[row][col] != 'F') {
        return; // 已经翻开或标记
    }
    
    if (game->board[row][col] == 'F') {
        return; // 被标记的格子不能翻开
    }
    
    // 踩到地雷
    if (game->mines_map[row][col] == '*') {
        game->board[row][col] = '*';
        game->game_over = 1;
        return;
    }
    
    // 翻开格子
    reveal_empty_cells(game, row, col);
    
    // 检查是否获胜
    if (game->cells_left == 0) {
        game->game_won = 1;
    }
}

// 标记/取消标记地雷
void toggle_flag(Game *game, int row, int col) {
    if (!is_valid(game, row, col)) {
        return;
    }
    
    if (game->board[row][col] == '#') {
        game->board[row][col] = 'F';
        game->mines_left--;
    } else if (game->board[row][col] == 'F') {
        game->board[row][col] = '#';
        game->mines_left++;
    }
}

// 显示所有地雷（游戏结束时）
void reveal_all_mines(Game *game) {
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            if (game->mines_map[i][j] == '*') {
                game->board[i][j] = '*';
            }
        }
    }
}

// ==================== 界面显示函数 ====================

// 显示游戏棋盘
void display_board(Game *game, int show_mines) {
    CLEAR_SCREEN();
    
    printf("\n==== 扫雷游戏 ====\n");
    printf("剩余地雷数: %d\n", game->mines_left);
    printf("剩余格子数: %d\n\n", game->cells_left);
    
    // 显示列号
    printf("    ");
    for (int j = 0; j < game->cols; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    printf("   +");
    for (int j = 0; j < game->cols; j++) {
        printf("---");
    }
    printf("\n");
    
    // 显示棋盘内容
    for (int i = 0; i < game->rows; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < game->cols; j++) {
            if (show_mines && game->mines_map[i][j] == '*') {
                printf("* ");
            } else if (game->board[i][j] == '0') {
                printf("  "); // 空白格显示为空格
            } else if (game->board[i][j] == 'F') {
                printf("F ");
            } else if (game->board[i][j] == '#') {
                printf("# ");
            } else {
                printf("%c ", game->board[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
    
    printf("\n");
    printf("操作说明:\n");
    printf("  1 - 翻开格子\n");
    printf("  2 - 标记/取消标记\n");
    printf("  3 - 查看地雷布局（作弊模式）\n");
    printf("  0 - 退出游戏\n");
}

// 显示地雷布局（作弊/调试模式）
void display_mines_layout(Game *game) {
    CLEAR_SCREEN();
    
    printf("\n==== 地雷布局 ====\n");
    printf("总地雷数: %d\n\n", game->mines);
    
    // 显示列号
    printf("    ");
    for (int j = 0; j < game->cols; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    printf("   +");
    for (int j = 0; j < game->cols; j++) {
        printf("---");
    }
    printf("\n");
    
    // 显示真实的地雷分布图
    for (int i = 0; i < game->rows; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < game->cols; j++) {
            if (game->mines_map[i][j] == '*') {
                printf("* "); // 地雷
            } else if (game->mines_map[i][j] == '0') {
                printf("  "); // 空白格
            } else {
                printf("%c ", game->mines_map[i][j]); // 数字
            }
            printf(" ");
        }
        printf("\n");
    }
    
    printf("\n提示：这是完整的地雷布局图\n");
    printf("  * - 地雷位置\n");
    printf("  数字 - 周围地雷数量\n");
    printf("  空白 - 周围无地雷\n\n");
    printf("按回车键返回游戏...");
    while (getchar() != '\n');
    getchar();
}

// 显示游戏结束信息
void display_game_over(Game *game) {
    reveal_all_mines(game);
    display_board(game, 0);
    
    if (game->game_won) {
        printf("\n🎉 恭喜你！你赢了！🎉\n\n");
    } else {
        printf("\n💣 游戏结束！你踩到地雷了！💣\n\n");
    }
}

// 获取用户输入
int get_user_input(Game *game, int *row, int *col, int *action) {
    printf("\n请选择操作 (1-翻开, 2-标记, 3-查看地雷, 0-退出): ");
    if (scanf("%d", action) != 1) {
        while (getchar() != '\n'); // 清空输入缓冲区
        return 0;
    }
    
    if (*action == 0) {
        return 0; // 退出
    }
    
    if (*action == 3) {
        return 3; // 查看地雷布局
    }
    
    if (*action != 1 && *action != 2) {
        printf("无效的操作！\n");
        return 0;
    }
    
    printf("请输入行号 (0-%d): ", game->rows - 1);
    if (scanf("%d", row) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    
    printf("请输入列号 (0-%d): ", game->cols - 1);
    if (scanf("%d", col) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    
    return 1;
}

// ==================== 主游戏循环 ====================

int main(void) {
    Game game;
    int first_move = 1;
    
    init_game(&game);
    
    printf("\n欢迎来到扫雷游戏！\n");
    printf("游戏规则：\n");
    printf("  - 翻开所有非地雷格子即可获胜\n");
    printf("  - 数字表示周围地雷的数量\n");
    printf("  - 用'F'标记可能的地雷位置\n");
    printf("  - '#'表示未翻开的格子\n\n");
    printf("按回车键开始游戏...");
    getchar();
    
    while (!game.game_over && !game.game_won) {
        display_board(&game, 0);
        
        int row, col, action;
        int result = get_user_input(&game, &row, &col, &action);
        
        if (result == 0) {
            if (action == 0) {
                printf("\n游戏已退出。\n");
                break;
            }
            printf("输入错误，请重试。\n");
            printf("按回车键继续...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        
        // 处理查看地雷布局
        if (result == 3) {
            // 如果还没布雷，先提示
            if (first_move) {
                printf("\n提示：地雷还未布置（首次点击后才会生成）。\n");
                printf("按回车键继续...");
                while (getchar() != '\n');
                getchar();
            } else {
                display_mines_layout(&game);
            }
            continue;
        }
        
        if (!is_valid(&game, row, col)) {
            printf("坐标超出范围，请重试。\n");
            printf("按回车键继续...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        
        // 第一次点击时布置地雷
        if (first_move) {
            place_mines(&game, row, col);
            first_move = 0;
        }
        
        // 执行操作
        if (action == 1) {
            reveal_cell(&game, row, col);
        } else if (action == 2) {
            toggle_flag(&game, row, col);
        }
    }
    
    // 游戏结束
    if (game.game_over || game.game_won) {
        display_game_over(&game);
    }
    
    return 0;
}
```
# 7 执行结果
```shell
==== 扫雷游戏 ====
剩余地雷数: 0
剩余格子数: 0

     0  1  2  3  4  5  6  7  8 
   +---------------------------
 0 | 1  *  3  2  1
 1 | 2  3  *  *  1
 2 | 1  *  3  2  1
 3 | 1  2  2  1           1  1
 4 |    1  *  1           2  *
 5 |    1  1  1     1  1  3  *
 6 |                1  *  2  1
 7 | 2  2  1        1  1  1
 8 | *  *  1

操作说明:
  1 - 翻开格子
  2 - 标记/取消标记
  3 - 查看地雷布局（作弊模式）
  0 - 退出游戏

🎉 恭喜你！你赢了！🎉
```

