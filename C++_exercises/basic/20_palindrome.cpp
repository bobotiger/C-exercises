#include <iostream>
using namespace std;
int main(){
    int n, num, digit, rev = 0;
    cout << "Enter an positive integer: ";
    cin >> num;
    
    n = num;

    do{
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    } while(n != 0);

    if(rev == num){
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}