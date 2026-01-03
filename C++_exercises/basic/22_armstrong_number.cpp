#include <iostream>
using namespace std;

// Armstrong number is a number that is equal to the sum of cubes of its digits.
int main(){
    int n, num, digit, sum = 0;
    cout << "Enter an positive integer: ";
    cin >> num;
    
    n = num;

    while(n != 0){
        digit = n % 10;
        sum += digit * digit * digit;
        n /= 10;
    }

    if(sum == num){
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}