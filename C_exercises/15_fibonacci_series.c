/*
 * 程序说明：生成斐波那契数列
 * 功能：输入项数n，输出斐波那契数列的前n项
 *       斐波那契数列：0, 1, 1, 2, 3, 5, 8, 13...
 */
#include <stdio.h>

int main(){
    int n, t1 = 0, t2 = 1, nextTerm = 0, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for(i = 1; i <= n; ++i){
        if(i == 1){
            printf("%d, ", t1);
            continue;
        }
        if(i == 2){
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        printf("%d", nextTerm);
        if(i != n) {
            printf(", ");
        }
    }
    return 0;
}