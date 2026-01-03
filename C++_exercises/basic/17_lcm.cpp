#include <iostream>
using namespace std;
/**
 * LCM(least common multiple): 
 *  能够整除a和b的最小正整数 
 *  LCM(a, b) = (a * b) / GCD(a, b)
 *  遍历 max(a,b) ~ a * b，尝试整除a和b，如果均为0，则为LCM
 * 
 */

int main(){
    int num1, num2, lcm;

    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    lcm = (num1 > num2) ? num1 : num2; // start from the greater number

    while(true){
        if(lcm % num1 == 0 && lcm % num2 == 0){
            cout << "LCM of " << num1 << " and " << num2 << " is " << lcm << endl;
            break;
        }
        ++lcm;
    }

    return 0;
}