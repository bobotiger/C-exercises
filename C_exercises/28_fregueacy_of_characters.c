/*
 * 程序说明：统计字符出现频率
 * 功能：在给定的字符串中，统计指定字符出现的次数
 */
#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "C++ programming is fun";
    char checkChar = 'g';
    int count = 0, i;

    for(i = 0; i < strlen(str); i++){
        if(str[i] == checkChar){
            count++;
        }
    }
    printf("The character '%c' appears %d times in the string.\n", checkChar, count);
    return 0;
}