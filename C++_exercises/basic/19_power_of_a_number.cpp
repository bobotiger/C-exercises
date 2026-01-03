#include <iostream>
using namespace std;

int main(){
    int exponent;
    double base, result = 1.0;

    cout << "Enter base and exponent respectively: ";
    cin >> base >> exponent;

    cout << base << "^" << exponent << " = ";

    for(int i = 1; i <= abs(exponent); ++i){
        result *= base;
    }

    if(exponent < 0){
        result = 1.0 / result;
    }
    cout << result << endl;
    return 0;
}