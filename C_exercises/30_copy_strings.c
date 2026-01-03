/*
 * 程序说明：字符串复制
 * 功能：输入一个字符串，将其复制到另一个字符串变量中
 */
#include <stdio.h>
#include <string.h>

int main(){
    char s1[100], s2[100];
    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;
    strcpy(s2, s1); // Copying s1 to s2
    printf("s2 = %s\n", s2);
    return 0;
}