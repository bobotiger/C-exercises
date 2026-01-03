/*
 * 程序说明：求一个数的所有因子
 * 功能：输入一个正整数，输出该数的所有因子（能整除该数的正整数）
 */
#include <stdio.h>

int main(){
    int n, i;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    for(i = 1; i <= n; ++i){
        if(n % i == 0){
            printf("%d ", i);
        }
    }
    return 0;
}