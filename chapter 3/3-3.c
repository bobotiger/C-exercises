#include <stdio.h>
/*
    输入学生人数n，以及n个学生的成绩 s [1..n]
    计算平均成绩：(s1+s2+s3+...+sn)/n
    统计及格学生人数：
        int count = 0;
        for(int i=0; i<n; i++){
            if(s >= 60){
                count += 1;
            }
        }
*/
int main(void){
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    double score;
    double sum = 0.0;
    int pass_count = 0;

    for(int i = 0; i < n; i++){
        printf("Enter score for student %d: ", i + 1);
        scanf("%lf", &score);
        sum += score;
        if(score >= 60){
            pass_count++;
        }
    }

    double average = sum / n;
    printf("Average score: %.2f\n", average);
    printf("Number of passing students: %d\n", pass_count);

    return 0;
}