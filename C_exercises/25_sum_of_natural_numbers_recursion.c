/*
 * 程序说明：使用递归计算自然数之和
 * 功能：输入一个正整数n，使用递归方法计算1到n的自然数之和
 */
#include <stdio.h>

int add(int n);

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Sum = %d\n", add(n));
    return 0;
}

int add(int n){
    if(n == 0)
        return 0;
    else
        return n + add(n - 1);
}