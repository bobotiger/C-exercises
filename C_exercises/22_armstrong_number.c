/*
 * 程序说明：判断阿姆斯特朗数（水仙花数）
 * 功能：输入一个正整数，判断该数是否为阿姆斯特朗数
 *       阿姆斯特朗数：各位数字的立方和等于该数本身，如153 = 1³ + 5³ + 3³
 */
#include <stdio.h>

int main(){
    int n, num, digit, sum = 0;
    printf("Enter an positive integer: ");
    scanf("%d", &num);
    
    n = num;

    while(n != 0){
        digit = n % 10;
        sum += digit * digit * digit;
        n /= 10;
    }

    if(sum == num){
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}