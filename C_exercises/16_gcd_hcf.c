/*
 * 程序说明：计算两个数的最大公约数（GCD/HCF）
 * 功能：输入两个正整数，计算并输出它们的最大公约数
 */
#include <stdio.h>

// GCD: Greatest Common Divisor
// HCF: Highest Common Factor

int main(){
    int num1, num2, gcd;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    for(int i = 1; i <= num1 && i <= num2; ++i){
        if(num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }

    printf("GCD of %d and %d is %d\n", num1, num2, gcd);
    return 0;
}