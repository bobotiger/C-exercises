#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int covert(string);

int main(){
    string n;
    cout << "Enter a binary number: ";
    cin >> n;

    cout << n << "(B) = " << covert(n) << "(D)" << endl;
    return 0;
}

int covert(string n){
    int decimalNumber = 0, i = 0;
    int len = n.length();
    for(int j = len - 1; j >= 0; j--){
        if(n[j] == '1'){
            decimalNumber += pow(2, i);
        }
        ++i;
    }
    return decimalNumber;
}