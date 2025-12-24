# 程序结构
## 控制结构

程序的控制结构决定了程序语句的执行顺序。C语言提供三种基本控制结构：顺序结构、分支结构（选择结构）和循环结构。

### C语言程序基础结构

一个完整的C语言程序由以下部分组成：

**基本程序框架**
```c
// 1. 预处理指令（可选）
#include <stdio.h>      // 包含标准输入输出库
#include <stdlib.h>     // 包含标准库函数
#define PI 3.14159      // 定义常量
#define MAX(a,b) ((a)>(b)?(a):(b))  // 定义宏

// 2. 全局声明（可选）
int globalVar = 100;    // 全局变量
void myFunction();      // 函数声明

// 3. main函数（必须，程序入口）
int main(void) {
    // 局部变量声明
    int a = 10;
    
    // 程序语句
    printf("Hello, World!\n");
    
    // 返回值
    return 0;
}

// 4. 其他函数定义（可选）
void myFunction() {
    printf("这是自定义函数\n");
}
```

**程序执行流程**
```
开始
  ↓
预处理（处理 #include、#define 等）
  ↓
编译（将源代码转换为目标代码）
  ↓
链接（将目标代码与库文件链接）
  ↓
运行（从 main 函数开始执行）
  ↓
结束（main 函数 return）
```

**完整示例**
```c
#include <stdio.h>
#define SIZE 100

// 函数声明
int add(int a, int b);
void printArray(int arr[], int n);

// 全局变量
int count = 0;

int main(void) {
    // 局部变量
    int num1 = 10, num2 = 20;
    int result;
    int arr[5] = {1, 2, 3, 4, 5};
    
    // 函数调用
    result = add(num1, num2);
    printf("Sum: %d\n", result);
    
    printArray(arr, 5);
    
    return 0;
}

// 函数定义
int add(int a, int b) {
    return a + b;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```

### 顺序结构

顺序结构是最基本的程序结构，程序按照语句的书写顺序从上到下依次执行。

**基本形式**
```c
语句1;
语句2;
语句3;
...
```

**执行流程**
```
语句1 → 语句2 → 语句3 → ...
```

**示例1：简单计算**
```c
#include <stdio.h>

int main(void) {
    int a = 10;           // 第1步：声明并初始化a
    int b = 20;           // 第2步：声明并初始化b
    int sum = a + b;      // 第3步：计算和
    printf("Sum = %d\n", sum);  // 第4步：输出结果
    return 0;             // 第5步：返回
}
```

**示例2：输入处理输出**
```c
#include <stdio.h>

int main(void) {
    double radius, area, circumference;
    const double PI = 3.14159;
    
    // 1. 提示用户输入
    printf("请输入圆的半径：");
    
    // 2. 接收输入
    scanf("%lf", &radius);
    
    // 3. 计算面积
    area = PI * radius * radius;
    
    // 4. 计算周长
    circumference = 2 * PI * radius;
    
    // 5. 输出结果
    printf("圆的面积：%.2f\n", area);
    printf("圆的周长：%.2f\n", circumference);
    
    return 0;
}
```

**示例3：变量交换**
```c
#include <stdio.h>

int main(void) {
    int a = 5, b = 10, temp;
    
    printf("交换前：a = %d, b = %d\n", a, b);
    
    // 使用临时变量交换
    temp = a;    // 第1步：保存a的值
    a = b;       // 第2步：将b的值赋给a
    b = temp;    // 第3步：将原a的值（保存在temp中）赋给b
    
    printf("交换后：a = %d, b = %d\n", a, b);
    
    return 0;
}
```

**顺序结构注意事项**
- 变量必须先声明后使用
- 变量应在使用前初始化或赋值
- 语句之间不能跳跃执行
- 表达式语句需要以分号 `;` 结尾

### 分支结构

分支结构（选择结构）根据条件的真假选择不同的执行路径。C语言提供 `if`、`if-else`、`if-else if-else` 和 `switch` 语句。

#### if 语句

**基本形式**
```c
if (条件表达式) {
    // 条件为真时执行的语句
}
```
**示例**
```c
int score = 85;

if (score >= 60) {
    printf("及格\n");
}

if (score >= 90) {
    printf("优秀\n");
}

// 单行语句可省略大括号（但不推荐）
if (score >= 60)
    printf("及格\n");  // 仅这一行属于if

// 多行必须用大括号
if (score >= 60) {
    printf("恭喜你！\n");
    printf("及格了\n");
}
```

#### if-else 语句

**基本形式**
```c
if (条件表达式) {
    // 条件为真时执行
} else {
    // 条件为假时执行
}
```
**示例**
```c
#include <stdio.h>

int main(void) {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);
    
    if (num % 2 == 0) {
        printf("%d 是偶数\n", num);
    } else {
        printf("%d 是奇数\n", num);
    }
    
    // 判断正负
    if (num >= 0) {
        printf("%d 是非负数\n", num);
    } else {
        printf("%d 是负数\n", num);
    }
    
    return 0;
}
```

#### if-else if-else 语句（多分支）

**基本形式**
```c
if (条件1) {
    // 条件1为真时执行
} else if (条件2) {
    // 条件1为假且条件2为真时执行
} else if (条件3) {
    // 条件1、2都为假且条件3为真时执行
} else {
    // 所有条件都为假时执行
}
```

**示例1：成绩评级**
```c
#include <stdio.h>

int main(void) {
    int score;
    printf("请输入成绩（0-100）：");
    scanf("%d", &score);
    
    if (score < 0 || score > 100) {
        printf("输入无效\n");
    } else if (score >= 90) {
        printf("等级：A（优秀）\n");
    } else if (score >= 80) {
        printf("等级：B（良好）\n");
    } else if (score >= 70) {
        printf("等级：C（中等）\n");
    } else if (score >= 60) {
        printf("等级：D（及格）\n");
    } else {
        printf("等级：F（不及格）\n");
    }
    
    return 0;
}
```

**示例2：判断三角形类型**
```c
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("请输入三角形三边长：");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    // 先判断能否构成三角形
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("不能构成三角形\n");
    } else if (a == b && b == c) {
        printf("等边三角形\n");
    } else if (a == b || a == c || b == c) {
        printf("等腰三角形\n");
    } else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        printf("直角三角形\n");
    } else {
        printf("普通三角形\n");
    }
    
    return 0;
}
```

#### 嵌套 if 语句

**基本形式**
```c
if (条件1) {
    if (条件2) {
        // 条件1和条件2都为真时执行
    } else {
        // 条件1为真但条件2为假时执行
    }
} else {
    // 条件1为假时执行
}
```

**示例：闰年判断**
```c
#include <stdio.h>

int main(void) {
    int year;
    printf("请输入年份：");
    scanf("%d", &year);
    
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d 是闰年\n", year);  // 能被400整除
            } else {
                printf("%d 不是闰年\n", year);  // 能被100整除但不能被400整除
            }
        } else {
            printf("%d 是闰年\n", year);  // 能被4整除但不能被100整除
        }
    } else {
        printf("%d 不是闰年\n", year);  // 不能被4整除
    }
    
    return 0;
}
```

**更简洁的写法（使用逻辑表达式）**
```c
#include <stdio.h>

int main(void) {
    int year;
    printf("请输入年份：");
    scanf("%d", &year);
    
    // 闰年条件：能被4整除且不能被100整除，或者能被400整除
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d 是闰年\n", year);
    } else {
        printf("%d 不是闰年\n", year);
    }
    
    return 0;
}
```

#### switch 语句

适合多个离散值的判断，比多重 if-else 更清晰。

**基本形式**
```c
switch (表达式) {
    case 常量1:
        // 表达式值等于常量1时执行
        break;
    case 常量2:
        // 表达式值等于常量2时执行
        break;
    case 常量3:
    case 常量4:
        // 表达式值等于常量3或4时执行
        break;
    default:
        // 所有case都不匹配时执行
        break;
}
```

**示例1：星期判断**
```c
#include <stdio.h>

int main(void) {
    int day;
    printf("请输入星期几（1-7）：");
    scanf("%d", &day);
    
    switch (day) {
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 7:
            printf("星期日\n");
            break;
        default:
            printf("输入无效\n");
            break;
    }
    
    return 0;
}
```

**示例2：简单计算器**
```c
#include <stdio.h>

int main(void) {
    double num1, num2, result;
    char op;
    
    printf("请输入表达式（如：5 + 3）：");
    scanf("%lf %c %lf", &num1, &op, &num2);
    
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("错误：除数不能为0\n");
            }
            break;
        default:
            printf("错误：不支持的运算符\n");
            break;
    }
    
    return 0;
}
```

**示例3：工作日/周末判断（case穿透）**
```c
#include <stdio.h>

int main(void) {
    int day;
    scanf("%d", &day);
    
    switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("工作日\n");
            break;
        case 6:
        case 7:
            printf("周末\n");
            break;
        default:
            printf("输入无效\n");
            break;
    }
    
    return 0;
}
```

**switch 注意事项**
- `switch` 的表达式必须是**整型**或**字符型**（char本质是整型）
- `case` 后面必须是**常量**，不能是变量或表达式
- `break` 语句用于跳出 switch，如果没有 break 会继续执行下一个 case（穿透）
- `default` 是可选的，通常放在最后
- 多个 case 可以共享同一段代码（case穿透特性）

### 循环结构

循环结构用于重复执行一段代码，直到满足退出条件。C语言提供三种循环：`while`、`do-while` 和 `for`。

#### while 循环

**基本形式**
```c
while (条件表达式) {
    // 循环体（条件为真时重复执行）
}
```
**示例1：输出1到10**
```c
#include <stdio.h>

int main(void) {
    int i = 1;
    
    while (i <= 10) {
        printf("%d ", i);
        i++;  // 重要：更新循环变量，避免死循环
    }
    printf("\n");
    
    return 0;
}
```

**示例2：计算1到100的和**
```c
#include <stdio.h>

int main(void) {
    int i = 1, sum = 0;
    
    while (i <= 100) {
        sum += i;
        i++;
    }
    
    printf("1到100的和 = %d\n", sum);  // 5050
    return 0;
}
```

**示例3：输入验证（哨兵循环）**
```c
#include <stdio.h>

int main(void) {
    int num, sum = 0, count = 0;
    
    printf("请输入数字（输入-1结束）：\n");
    scanf("%d", &num);
    
    while (num != -1) {
        sum += num;
        count++;
        scanf("%d", &num);
    }
    
    if (count > 0) {
        printf("平均值 = %.2f\n", (double)sum / count);
    } else {
        printf("没有输入数据\n");
    }
    
    return 0;
}
```

#### do-while 循环

**基本形式**
```c
do {
    // 循环体（至少执行一次）
} while (条件表达式);
```
**与 while 的区别**
- `while`：先判断条件，再执行循环体（可能一次都不执行）
- `do-while`：先执行循环体，再判断条件（至少执行一次）

**示例1：菜单程序**
```c
#include <stdio.h>

int main(void) {
    int choice;
    
    do {
        printf("\n========= 菜单 =========\n");
        printf("1. 选项1\n");
        printf("2. 选项2\n");
        printf("3. 选项3\n");
        printf("0. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("你选择了选项1\n");
                break;
            case 2:
                printf("你选择了选项2\n");
                break;
            case 3:
                printf("你选择了选项3\n");
                break;
            case 0:
                printf("退出程序\n");
                break;
            default:
                printf("无效选择，请重新输入\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}
```
**示例2：密码验证**
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char password[20];
    const char correctPassword[] = "123456";
    int attempts = 0;
    const int maxAttempts = 3;
    
    do {
        printf("请输入密码：");
        scanf("%s", password);
        attempts++;
        
        if (strcmp(password, correctPassword) == 0) {
            printf("密码正确，欢迎！\n");
            break;
        } else {
            printf("密码错误！");
            if (attempts < maxAttempts) {
                printf("还有 %d 次机会\n", maxAttempts - attempts);
            }
        }
    } while (attempts < maxAttempts);
    
    if (attempts >= maxAttempts && strcmp(password, correctPassword) != 0) {
        printf("尝试次数过多，账户已锁定\n");
    }
    
    return 0;
}
```

#### for 循环

**基本形式**
```c
for (初始化; 条件表达式; 更新表达式) {
    // 循环体
}
```
**等价的 while 循环**
```c
初始化;
while (条件表达式) {
    循环体;
    更新表达式;
}
```

**示例1：基本用法**
```c
#include <stdio.h>

int main(void) {
    // 输出1到10
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 倒序输出10到1
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 步长为2
    for (int i = 0; i <= 20; i += 2) {
        printf("%d ", i);  // 0 2 4 6 ... 20
    }
    printf("\n");
    
    return 0;
}
```

**示例2：遍历数组**
```c
#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 正向遍历
    printf("数组元素：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 计算数组和
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("数组和：%d\n", sum);
    
    // 查找最大值
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("最大值：%d\n", max);
    
    return 0;
}
```

**示例3：嵌套循环（乘法表）**
```c
#include <stdio.h>

int main(void) {
    // 九九乘法表
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%2d  ", j, i, i*j);
        }
        printf("\n");
    }
    
    return 0;
}
```

**示例4：矩阵遍历**
```c
#include <stdio.h>
#define ROW 3
#define COL 4

int main(void) {
    int matrix[ROW][COL] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // 遍历二维数组
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

**for 循环的灵活性**
```c
// 1. 省略初始化
int i = 0;
for (; i < 10; i++) {
    printf("%d ", i);
}

// 2. 省略更新
for (int i = 0; i < 10; ) {
    printf("%d ", i);
    i++;
}

// 3. 省略条件（无限循环）
for (int i = 0; ; i++) {
    if (i >= 10) break;
    printf("%d ", i);
}

// 4. 全部省略（无限循环）
for (;;) {
    // 需要用 break 退出
}

// 5. 多变量
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d, j=%d\n", i, j);
}
```

#### 循环控制语句

**break 语句**：立即退出循环

```c
// 示例1：查找数组中的元素
#include <stdio.h>

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("找到 %d 在位置 %d\n", target, i);
            found = 1;
            break;  // 找到后立即退出循环
        }
    }
    
    if (!found) {
        printf("未找到 %d\n", target);
    }
    
    return 0;
}

// 示例2：break 只退出最内层循环
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (j == 1) break;  // 只退出内层循环
        printf("i=%d, j=%d\n", i, j);
    }
}
// 输出：i=0,j=0  i=1,j=0  i=2,j=0
```

**continue 语句**：跳过本次循环，继续下一次

```c
// 示例1：输出1到10的奇数
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // 跳过偶数
        }
        printf("%d ", i);  // 只输出奇数
    }
    printf("\n");  // 输出：1 3 5 7 9
    
    return 0;
}

// 示例2：过滤无效输入
int main(void) {
    int sum = 0, count = 0;
    
    for (int i = 0; i < 5; i++) {
        int num;
        printf("请输入第 %d 个数：", i + 1);
        scanf("%d", &num);
        
        if (num < 0) {
            printf("负数无效，跳过\n");
            continue;  // 跳过负数
        }
        
        sum += num;
        count++;
    }
    
    if (count > 0) {
        printf("平均值 = %.2f\n", (double)sum / count);
    }
    
    return 0;
}
```

#### 循环选择建议

| 循环类型 | 适用场景 | 示例 |
|---------|---------|------|
| **for** | 循环次数已知或可推导（计数型循环） | 遍历数组索引 0..n-1；固定 100 次求和 |
| **while** | 循环次数未知，条件先判断（可能 0 次） | 从输入读取直到 EOF/哨兵；重试直到条件满足 |
| **do-while** | 至少执行一次，条件后判断 | 菜单交互（先显示菜单再判退出）；密码输入至少验证一遍 |

**综合示例：质数判断**
```c
#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    
    if (n <= 1) {
        printf("%d 不是质数\n", n);
        return 0;
    }
    
    int isPrime = 1;  // 假设是质数
    
    // 只需检查到 sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = 0;  // 找到因子，不是质数
            break;
        }
    }
    
    if (isPrime) {
        printf("%d 是质数\n", n);
    } else {
        printf("%d 不是质数\n", n);
    }
    
    return 0;
}
```

**常见循环模式（含用途说明）**
```c
// 1. 累加器模式：不断叠加求和/求积等聚合量
int sum = 0;
for (int i = 1; i <= n; i++) {
    sum += i;
}

// 2. 计数器模式：统计满足条件的元素个数
int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
        count++;
    }
}

// 3. 查找模式：按条件查找，找到即退出
int found = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        found = 1;
        break;
    }
}

// 4. 最值模式：一路维护当前最优（最大/最小）
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}

// 5. 哨兵循环模式：以特定值终止输入/处理
scanf("%d", &num);
while (num != -1) {
    // 处理 num
    scanf("%d", &num);
}
```

## 函数

函数是封装可复用逻辑的基本单元。核心关注：定义与声明、参数传递、返回值、作用域与存储期、递归、模块化设计。

### 函数的定义与声明

函数定义包含返回类型、函数名、参数列表与函数体：
```c
int add(int a, int b) {
    return a + b;
}

void print_msg(const char *msg) {
    printf("%s\n", msg);
}
```

函数声明（原型）在调用前告知编译器签名，以进行类型检查：
```c
int add(int a, int b);
void print_msg(const char *msg);

int main(void) {
    printf("%d\n", add(2, 3));
    print_msg("hello");
    return 0;
}

// 定义可位于声明之后
int add(int a, int b) { return a + b; }
void print_msg(const char *msg) { printf("%s\n", msg); }
```

最佳实践：将对外可见的函数声明放入头文件，使用包含保护避免重复包含：
```c
// math.h
#ifndef MATH_H
#define MATH_H

int add(int a, int b);
int multiply(int a, int b);

#endif
```

### 参数传递：值传递与指针

C 语言按值传递：实参的值复制给形参，形参修改不影响调用者。
```c
void increment(int x) {
    x = x + 1;
}

int main(void) {
    int a = 5;
    increment(a);
    printf("%d\n", a);  // 仍为 5
    return 0;
}
```

需要在函数内修改调用者变量时，传递其地址：
```c
void increment(int *x) {
    *x = *x + 1;
}

int main(void) {
    int a = 5;
    increment(&a);
    printf("%d\n", a);  // 6
    return 0;
}
```

数组参数会衰变为指向首元素的指针，无法凭参数获知长度，需显式传入：
```c
void sum_array(const int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("sum = %d\n", sum);
}
```

### 变量的作用域与存储期

1) 自动变量（局部，自动存储期）
- 块内可见，进入块创建、离开块销毁；未初始化值不确定。
```c
void func(void) {
    int x = 10;
    if (x > 5) {
        int y = 20;
    }
}
```

2) 静态局部变量（块作用域，静态存储期）
- 初始化一次，程序运行期始终存在；未显式初始化默认为 0。
```c
void counter(void) {
    static int count = 0;
    count++;
    printf("count = %d\n", count);
}
```

3) 全局变量（外部变量，静态存储期，文件作用域）
```c
int global_count = 0;

void inc(void) { global_count++; }

int main(void) {
    inc();
    printf("%d\n", global_count);
    return 0;
}
```

4) 静态全局变量（内部连接）
- 仅当前源文件可见，避免与其他文件符号冲突。
```c
static int private_var = 42;
static void helper(void) { /* ... */ }
```

5) 跨文件引用（外部连接）
```c
// a.c
int shared = 100;  // 定义

// b.c
extern int shared;  // 声明
void use(void) { printf("%d\n", shared); }
```

### 递归调用

递归需同时具备基例与递进：
```c
long long factorial(int n) {
    if (n == 0) return 1;          // 基例
    return n * factorial(n - 1);   // 递进
}

long long fib(int n) {
    if (n <= 1) return n;          // 基例
    return fib(n - 1) + fib(n - 2);
}
```
注意性能与栈深度；规模较大时优先循环或使用记忆化/迭代实现。

### 函数与模块化设计

- 单一职责：每个函数聚焦一件事。
- 清晰接口：参数与返回值语义明确，副作用可控。
- 合理作用域：使用 `static` 隐藏内部实现，减少全局可变状态。
- 文件组织：公共声明放在 `.h`，实现放在 `.c`，调用方 `#include` 头文件。

```c
// math.h
#ifndef MATH_H
#define MATH_H
int add(int a, int b);
int multiply(int a, int b);
#endif

// math.c
#include "math.h"
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// main.c
#include "math.h"
#include <stdio.h>
int main(void) {
    printf("%d\n", add(2, 3));
    printf("%d\n", multiply(2, 3));
    return 0;
}
```
