/*
 * 程序说明：判断回文数
 * 功能：输入一个正整数，判断该数字是否为回文数
 *       回文数：正读和反读都相同的数字，如121、12321
 */
#include <stdio.h>

int main(){
    int n, num, digit, rev = 0;
    printf("Enter an positive integer: ");
    scanf("%d", &num);
    
    n = num;

    do{
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    } while(n != 0);

    if(rev == num){
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }
    return 0;
}