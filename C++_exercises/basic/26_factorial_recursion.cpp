#include <iostream>
using namespace std;

double fctorial(double n);

int main(){
    double n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << fctorial(n) << endl;
    return 0;
}

double fctorial(double n){
    if(n <= 1)
        return 1;
    else
        return n * fctorial(n - 1);
}