/*
 * 程序说明：反转数字
 * 功能：输入一个整数，输出该整数的反转结果
 *       例如：输入123，输出321
 */
#include <stdio.h>

int main(){
    int n, reversedNumber = 0, digit;
    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n != 0){
        digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }

    printf("Reversed Number: %d\n", reversedNumber);
    return 0;
}