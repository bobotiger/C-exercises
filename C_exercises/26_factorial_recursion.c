/*
 * 程序说明：使用递归计算阶乘
 * 功能：输入一个正整数n，使用递归方法计算n的阶乘（n!）
 */
#include <stdio.h>

double fctorial(double n);

int main(){
    double n;
    printf("Enter a positive integer: ");
    scanf("%lf", &n);

    printf("Factorial of %.0lf = %.0lf\n", n, fctorial(n));
    return 0;
}

double fctorial(double n){
    if(n <= 1)
        return 1;
    else
        return n * fctorial(n - 1);
}