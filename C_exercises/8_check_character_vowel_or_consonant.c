/*
 * 程序说明：检查字符是元音还是辅音
 * 功能：输入一个字符，判断该字符是元音字母还是辅音字母
 */
#include <stdio.h>
#include <ctype.h>

int main(void){
    char ch;
    int isLowercaseVowel, isUppercaseVowel;

    printf("Enter an alphabet: ");
    scanf("%c", &ch);
    isLowercaseVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    isUppercaseVowel = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    if (!isalpha(ch))
        printf("Error! Non-alphabetic character entered.");
    else if (isLowercaseVowel || isUppercaseVowel)
        printf("%c is a vowel.\n", ch);
    else
        printf("%c is a consonant.\n",ch);
    return 0;
}