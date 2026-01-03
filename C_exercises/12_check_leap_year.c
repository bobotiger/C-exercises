/*
 * 程序说明：判断闰年
 * 功能：输入一个年份，判断该年份是否为闰年
 *       闰年判断规则：能被4整除但不能被100整除，或者能被400整除
 */
#include <stdio.h>

int main(){
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("%d is a leap year.", year);
    else
        printf("%d is not a leap year.", year);
    
    printf("\n");
    // 等价 if分支结构
    if(year % 4 == 0){
        if(year % 100 != 0){
            printf("%d is a leap year.", year);
        } else {
            if(year % 400 == 0){
                printf("%d is a leap year.", year);
            } else {
                printf("%d is not a leap year.", year);
            }
        }
    } else {
        printf("%d is not a leap year.", year);
    }    
    return 0;
}