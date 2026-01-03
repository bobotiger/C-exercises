/*
 * 程序说明：判断素数（质数）
 * 功能：输入一个正整数，判断该数是否为素数
 *       素数：只能被1和自身整除的大于1的自然数
 */
#include <stdio.h>

int main(){
    int i, n, isPrime = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n == 0 || n == 1){
        isPrime = 0;
    } else {
        for(i = 2; i <= n / 2; ++i){
            if(n % i == 0){
                isPrime = 0;
                break;
            }
        }
    }
    if(isPrime)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
    
    return 0;
}