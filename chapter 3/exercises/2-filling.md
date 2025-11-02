# 二 填空题
## 1
- 执行以下程序段，若输入 32，则输出`_____1____`；若输入 58，则输出`____2_____`。
```c
int a;
scanf("%d", &a);
if(a > 50) printf("%d", a);
if(a > 40) printf("%d", a);
if(a > 30) printf("%d", a);
```
### 答案
1. 32
2. 585858

- 输入 32：只有 a > 30 条件成立，执行一次 printf。
- 输入 58：a > 50、a > 40、a > 30 条件都成立，执行 3 次 printf，所以输出为三次连续的数字 58。

## 2
- 表示条件 10 < x < 100 或者 x < 0 的 C 语言表达式是__________。

### 答案
```c
(10<x && x<100) || (x<0)
```
- `10 < x && x < 100` 表示 `x` 在 `10~100` 之间
- `|| x < 0` 表示 `x` 小于 `0` 也符合条件。

## 3
- 输出偶数。输入一个正整数 n，再输入 n 个整数，输出其中的偶数。
- 要求相邻偶数中间用一个空格分开，行末不得有多余空格。请填空。
```c
char ch;
int first = 1, k, n, x;

scanf("%d", &n);
for(k = 1; k <= n; k++) {
    scanf("%d", &x);
    if(____1____) {
        if(____2____){ 
            printf("%d", x);
            ____3____;
        }else{
            ____4____;
        }
    }
}
```
### 答案
1. `x%2==0`
2. `first`
3. `first=0`
4. `printf(" %d",x)`

```c
char ch;
int first = 1, k, n, x;

scanf("%d", &n);
for(k = 1; k <= n; k++) {
    scanf("%d", &x);
    if(x%2==0) {              // ① 判断偶数
        if(first) {           // ② 第一次输出
            printf("%d", x);
            first=0;          // ③ 改为后续输出模式
        } else {
            printf(" %d",x);  // ④ 后续输出前加空格
        }
    }
}
```
## 4
- 以下程序段的运行结果是(      )。
```c
int k = 16;
switch(k % 3) {
    case 0: printf("zero");
    case 1: printf("one");
    case 2: printf("two");
}
```
### 答案
- 输出: onetwo
- `k % 3 = 1`，进入 `case 1:`，但 `switch` 没有 `break`，所以会继续执行 `case 2`，依次输出 `one` 和 `two`。


## 5
- 找出 3 个整数中最大的数。输入 3 个整数，输出其中最大的数。请填空。
```c
int a, b, c, max;
scanf("%d %d %d", &a, &b, &c);
if(a > b)
    if(a > c) ___1___;
    else ___2___;
else
    if(___3____) max = b;
    else ___4___;

printf("The max is %d\n", max);

```

### 答案
1. `max=a`
2. `max=c`
3. `b>c`
4. `max=c`

```c
int a, b, c, max;
scanf("%d %d %d", &a, &b, &c);
if(a > b)
    if(a > c) max=a;           // a 最大
    else max=c;                // c 最大
else
    if(b>c) max = b;           // b 最大
    else max=c;                // c 最大

printf("The max is %d\n", max);

```
- 嵌套 if 用来比较三数，按逻辑找到最大值赋给 max。
- 分别比较 a、b、c，保证最大值正确输出。