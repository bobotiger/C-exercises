# 填空题
## 1
- 下列程序的输出结果为 ______
```c
int funp(int m);
int main(void)
{
    int n;
    for(n = 1; n < 10; n++)
        if(funp(n) == 1) printf("%d#", n);
    return 0;
}

int funp(int m)
{
    int i;
    if(m == 2 || m == 3) return 1;
    if(m < 2 || m % 2 == 0) return 0;
    for(i = 3; i < m; i = i + 2)
        if(m % i == 0) return 0;
    return 1;
}
```

### 解析
- funp函数
  - 返回值：int
  - 形参列表：int m
  - 功能：
    - m=2 或 =3 时          return 1
    - m<2 或 m>3 且为偶数    return 0
    - m能被`[3~m)`间的奇数整除 return 0
    - 否则情况返回 1
- 主函数
  - 循环处理 n = 1 ~ 9
    - 每次循环调用funp(n)
      - 如果返回1，则打印n的值
      - 否则，执行下一次循环

- 因此执行结果，就是n从1-9 满足funp输出1时的值
  - m=1 return 0
  - m=2 return 1
  - m=3 return 1
  - m=4 return 0
  - m=5 return 1
  - m=6 return 0
  - m=7 return 1
  - m=8 return 0
  - m=9 return 0

- 答案
```
2#3#5#7#
```

## 2
判断正整数的各位数字是否按从小到大排列。输入一批正整数（以零或负数为结束标志），判断每个数从高位到低位的各位数字是否按值从小到大排列。要求定义和调用函数 fun(m) 判断 m 中各位数字是否按值从小到大排列，满足条件返回 1，否则返回 0。填空如下：
```c
______;  
int main(void)
{
    int n;
    scanf("%d", &n);
    while(n > 0) {
        if(________) {
            printf("%d 中各位数字按从小到大排列\n", n);
        } else {
            printf("%d 中各位数字没有按从小到大排列\n", n);
        }
        scanf("%d", &n);
    }
    return 0;
}

int fun(_______)
{
    int cur_digit, old_digit = m % 10;
    while(m > 10) {
        _______;
        cur_digit = m % 10;
        if(cur_digit >= old_digit)
            return 0;
        _______;
    }
    return 1;
}

```

### 解析
- fun()函数
  - 从题目描述可知，其接收一个整数作为参数，因此形参列表为 int m
  - fun()的主要功能时判定m的各位数是否按值从小到大排列
    - old_digit = m % 10; 首先获得了m的个位数值
    - 在循环中，需要先获取m的十位数值，因此
      - m = m / 10;
      - cur_digit = m % 10; 这样cur_digit中保存当前个位，即原来的十位数值
      - 比较cur_digit 和 old_digit
        - 如果 十位 >= 各位 则不是从小到大排列，则返回0
        - 否则，将cur_digit的值保存到old_digit中，即 old_digit = cur_digit
      - 继续下一次循环
  - 直到m的所有数位都处理完毕，并返回1，表示m的各数位值是按从小到大排列的

- 在main()函数中需要调用fun()，而fun()定义于main函数之后，因此，需要在main()函数前声明fun()函数
  - int fun(int m);
- 在while(n>0){...}的循环中批量处理多个正整数，每次循环处理一个正整数，
  - 每次调用fun(n)
    - 如果返回1，则输出"n中各位数字按从小到大排列"
    - 否则返回0，则输出"n中各位数字没有按从小到大排列"
  - 读取下一个正整数，并继续下一次循环，
  - 输入0或负数时，循环结束

- 完整代码
```c
int fun(int m);  
int main(void)
{
    int n;
    scanf("%d", &n);
    while(n > 0) {
        if(fun(n)) {
            printf("%d 中各位数字按从小到大排列\n", n);
        } else {
            printf("%d 中各位数字没有按从小到大排列\n", n);
        }
        scanf("%d", &n);
    }
    return 0;
}

int fun(int m)
{
    int cur_digit, old_digit = m % 10;
    while(m > 10) {
        m=m/10;
        cur_digit = m % 10;
        if(cur_digit >= old_digit)
            return 0;
        old_digit=cur_digit;
    }
    return 1;
}

```

- 执行结果
```
123
123 中各位数字按从小到大排列
345
345 中各位数字按从小到大排列
321
321 中各位数字没有按从小到大排列
113
113 中各位数字没有按从小到大排列
0
```

## 3
- 输出 Yes 或 No。输入字符 'y' 或 'Y'，则在屏幕上输出字符串 "Yes."；输入其他字符，则在屏幕上输出字符串 "No!"。要求定义和调用函数 YesNo(ch)，当 ch 为 'y' 或 'Y' 时输出 "Yes."，当 ch 为其他字符时输出 "No!"。请填空。
```c
void YesNo(_______)
{
    switch(ch) {
        case 'y':
        case 'Y': _______
        default:  _______
    }
}

int main(void)
{
    char ch;
    printf("Please input a character:\n");
    ch = getchar();
    _______
    return 0;
}

```

### 解析
- YesNo()函数，接收一个字符型参数ch，因此形参列表为 char ch
- 如果ch
  - = 'y' 或 = 'Y'时，屏幕上输出字符串"Yes."
    - 因此需填入，printf("Yes.\n");break;
  - = 其他字符，屏幕上输出字符串"No!"
    - 因此需填入，printf("No!\n");
- main()函数
  - 通过getchar()从键盘接收一个字符，保存到ch变量中
  - 调用YesNo()函数，即YesNo(ch);

- 完整代码
```c
void YesNo(char ch)
{
    switch(ch) {
        case 'y':
        case 'Y': printf("Yes.\n");break;
        default:  printf("No!\n");
    }
}

int main(void)
{
    char ch;
    printf("Please input a character:\n");
    ch = getchar();
    YesNo(ch);
    return 0;
}

```
- 执行结果
```
Please input a character:
y
Yes.

Please input a character:
Y
Yes.

Please input a character:
n
No!

Please input a character:
t
No!
```