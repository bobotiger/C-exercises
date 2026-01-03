/*
 * 程序说明：二进制转十进制
 * 功能：输入一个二进制数字符串，将其转换为十进制数并输出
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

int covert(char*);

int main(){
    char n[65];
    printf("Enter a binary number: ");
    scanf("%s", n);

    printf("%s(B) = %d(D)\n", n, covert(n));
    return 0;
}

int covert(char* n){
    int decimalNumber = 0, i = 0, j;
    int len = strlen(n);
    for(j = len - 1; j >= 0; j--){
        if(n[j] == '1'){
            decimalNumber += (int)pow(2, i);
        }
        ++i;
    }
    return decimalNumber;
}