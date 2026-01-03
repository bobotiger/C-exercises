/*
 * 程序说明：计算两个数的最小公倍数（LCM）
 * 功能：输入两个正整数，计算并输出它们的最小公倍数
 */
#include <stdio.h>
/**
 * LCM(least common multiple): 
 *  能够整除a和b的最小正整数 
 *  LCM(a, b) = (a * b) / GCD(a, b)
 *  遍历 max(a,b) ~ a * b，尝试整除a和b，如果均为0，则为LCM
 * 
 */

int main(){
    int num1, num2, lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    lcm = (num1 > num2) ? num1 : num2; // start from the greater number

    while(1){
        if(lcm % num1 == 0 && lcm % num2 == 0){
            printf("LCM of %d and %d is %d\n", num1, num2, lcm);
            break;
        }
        ++lcm;
    }

    return 0;
}