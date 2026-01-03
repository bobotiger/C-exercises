/*
 * 程序说明：找出三个数中的最大值
 * 功能：输入三个数字，程序输出其中的最大值
 */
#include <stdio.h>

int main(){
    double num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%lf%lf%lf",&num1,&num2,&num3);

    if (num1 >= num2 && num1 >= num3)
        printf("Maximum number is: %.2f\n", num1);
    else if (num2 >= num1 && num2 >= num3)
        printf("Maximum number is: %.2f\n", num2);
    else
        printf("Maximum number is: %.2f\n", num3);
}