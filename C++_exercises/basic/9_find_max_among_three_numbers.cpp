#include <iostream>
using namespace std;

int main(){
    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    if (num1 >= num2 && num1 >= num3)
        cout << "Maximum number is: " << num1;
    else if (num2 >= num1 && num2 >= num3)
        cout << "Maximum number is: " << num2;
    else
        cout << "Maximum number is: " << num3;
}