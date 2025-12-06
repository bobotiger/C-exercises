# 填空题
## 1
- 输出一维数组最大元素和最小元素的下标。查找一维数组的最大元素和最小元素的下标，分别存放在函数 main() 的 maxsub 和 minsub 变量中。请填空。
```c
void find(int *, int, int *, int *);

int main(void)
{
    int maxsub, minsub, a[ ] = {5, 3, 7, 9, 2, 0, 4, 1, 6, 8};
    find(___1___);
    printf("maxsub=%d, minsub=%d\n", maxsub, minsub);
    return 0;
}

void find(int *a, int n, int *maxsub, int *minsub)
{
    int i;
    *maxsub = *minsub = 0;
    for(i = 1; i < n; i++){
        if(a[i] > a[*maxsub]) __2___;
        if(a[i] < a[*minsub]) __3___;
    }
}
```
### 参考答案
```c
void find(int *, int, int *, int *);

int main(void)
{
    int maxsub, minsub, a[ ] = {5, 3, 7, 9, 2, 0, 4, 1, 6, 8};
    // 函数调用：参数数量、顺序、类型均与形式参数列表一致
    find(a, 10, &maxsub, &minsub);
    printf("maxsub=%d, minsub=%d\n", maxsub, minsub);
    return 0;
}

void find(int *a, int n, int *maxsub, int *minsub)
{
    int i;
    *maxsub = *minsub = 0;
    for(i = 1; i < n; i++){
        if(a[i] > a[*maxsub]) *maxsub=i; // 保存当前最大元素下标到maxsub指针指向的内存空间中
        if(a[i] < a[*minsub]) *minsub=i; // 保存当前最小元素下标到minsub指针指向的内存空间中
    }
}
```

## 2
- 数组插值。函数 insert() 的功能是在一维数组 a 中将 x 插入到下标为 i (i >= 0) 的元素前，如果 i >= 元素个数，则 x 插入到末尾，元素个数存放在指针 n 所指向的变量中，插入后元素个数加 1。请填空。
```c
void insert(int a[ ], int *n, int x, int i)
{
    int j;
    if(____1___){
        for(j = *n - 1; ___2___; j--){
            ___3___ = a[j];
        }
    }else{
        i = *n;
    }

    a[i] = ___4___;
    (*n)++;
}
```
### 参考答案
- 向数组中插入一个新元素时，数组长度会增加1，且插入位置及其后面的元素均需向后移动一个位置；
```c
void insert(int a[ ], int *n, int x, int i)
{
    int j;
    if(i<*n){
        for(j = *n - 1; j>=i; j--){
            a[j+1] = a[j];
        }
    }else{
        i = *n;
    }

    a[i] = x;
    (*n)++;
}

void print_array(int a[], int len){
    for(int i=0; i<len; i++){
        if(i>0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main(void){
    int array[100] = {1,2,3,4,5,6,7,8};
    int len = 8;
    insert(array, &len, 100, 5);
    print_array(array, len);
    insert(array,&len, 200,20);
    print_array(array,len);
}
```
- 执行验证结果
```
1 2 3 4 5 100 6 7 8
1 2 3 4 5 100 6 7 8 200
```

## 3
- 判断回文。先消除输入字符串 s 的前后空格，再判断其是否为“回文”（即字符串正读和倒读都是一样的），若是则输出 Yes，否则输出 No。请填空。
```c
char ch, s[80], *p, *q;
int i, j, n;
gets(s);
p = ___1____;
while(*p == ' '){
    ___2____;
}
n = strlen(s);
q = ___3____;
while(*q == ' '){
    q--;
}
while(___4____ && *p == *q){
    p++;
    ___5____;
}
if(p < q) printf("No\n");
else printf("Yes\n");
```
### 参考答案
- 本题采用双指针，从字符串头 与 字符串尾 同时向中间移动处理；
```c
#include <string.h>
int main(void){
    char ch, s[80], *p, *q;
    int i, j, n;
    gets(s);
    // 指针p指向字符串首字符
    p = s;
    // 清除开头的所有空格字符
    while(*p == ' '){
        p++;
    }
    n = strlen(s);
    // 指针q指向字符串的最后一个字符
    q = s+n-1;
    // 清除字符串尾部的所有空格字符
    while(*q == ' '){
        q--;
    }
    // 同时从首尾向中心移动处理
    while((q-p)>=0 && *p == *q){
        p++;
        q--;
    }
    if(p < q) printf("No\n");
    else printf("Yes\n");
}
```
- 执行验证结果
```
     sdfsdf fdsfds   
Yes
  little   
No
```
## 4
- 最大字符移位。在字符串 str 中找出最大的字符，将在该字符前的所有字符往后顺序移动一位，再把最大字符放在字符串的第一个位置上。如 "knowledge" 变成 "wknoledeg"。请填空。
```c
char max, str[80], *p = str, *q = str;
gets(p);
max = *(p++);
while(*p != '\0'){
    if(max < *p){
        max = *p;
        ___1___;
    }
    p++;
}

p = q;
while(____2___){
    ___3___;
    p--;
}

*p = max;
puts(p);
```
### 参考答案
```c
int main(void){
    char max, str[80], *p = str, *q = str;
    gets(p);
    // 假设最大字符为第一个字符
    max = *(p++);
    // 循环遍历直到最后一个字符
    while(*p != '\0'){
        // 如果当前最大值小于当前指针p指向的字符
        if(max < *p){
            // 更新max
            max = *p;
            // 记录当前最大值的位置
            q=p;
        }
        p++;
    }
    // 将找到序列中最大值所在的地址赋值给指针p
    p = q;
    // 依次将str第一个字符到*p指向的字符间所有字符依次向后移动一位
    while((p - str)>0){
        *p = *(p-1);
        p--;
    }

    *p = max;
    puts(p);
}
```
- 执行验证结果
```
Helloworld
wHelloorld

Hello World!
rHello Wold!
```

## 5
- 字符传送。将字符串 s1 的所有字符传送到字符串 s2 中，要求每传送 3 个字符就再存放一个星号。如字符串 s1 为 "abcdefg"，则字符串 s2 为 `"abc*def*g"`。请填空。
```c
char s1[80], s2[80], *p = s1;
int cnt = 0, k = 0;
gets(p);
while(*p != '\0'){
    s2[k] = *p;
    k++; p++; cnt++;
    if( ______ ){
        s2[k] = '*';
        ______ ;
        ______ ;
    }
}
s2[k] = '\0';
puts(s2);
```
### 参考答案
```c
int main(void){
    char s1[80], s2[80], *p = s1;
    int cnt = 0, k = 0;
    gets(p);
    // 循环遍历字符串直到最后一个字符
    while(*p != '\0'){
        // 将指针p指向的字符数组s1中的字符存放到s2[k]中
        s2[k] = *p;
        // 下标，指针以及字符统计(每3个字符后添加一个星号)均累加1
        k++; p++; cnt++;
        // 如果已经复制3个字符
        if( cnt % 3 == 0 ){
            s2[k] = '*';
            // 重新开始统计
            cnt = 0 ;
            // 移动到下一个s2的存放位置
            k++;
        }
    }
    // 在s2字符数组中复制的最后一个有效字符后添加一个终止符，以便可以整体输出字符串
    s2[k] = '\0';
    puts(s2);
}
```
- 执行验证结果
```
sdafsadgasdfsgasdf
sda*fsa*dga*sdf*sga*sdf*
```

