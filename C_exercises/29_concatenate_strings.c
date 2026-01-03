/*
 * 程序说明：字符串连接
 * 功能：输入两个字符串，将它们连接成一个字符串并输出
 */
#include <stdio.h>
#include <string.h>

int main(){
    char s1[100], s2[100], concatenated[200];
    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;
    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;
    
    strcpy(concatenated, s1);
    strcat(concatenated, s2);
    
    printf("Concatenated string: %s\n", concatenated);
    return 0;
}