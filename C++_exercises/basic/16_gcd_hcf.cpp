#include <iostream>
using namespace std;

// GCD: Greatest Common Divisor
// HCF: Highest Common Factor


int main(){
    int num1, num2, gcd;

    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    for(int i = 1; i <= num1 && i <= num2; ++i){
        if(num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }

    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << endl;
    return 0;
}