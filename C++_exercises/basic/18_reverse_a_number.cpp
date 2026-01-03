#include <iostream>
using namespace std;

int main(){
    int n, reversedNumber = 0;
    cout << "Enter an integer: ";
    cin >> n;

    while(n != 0){
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }

    cout << "Reversed Number: " << reversedNumber << endl;
    return 0;
}