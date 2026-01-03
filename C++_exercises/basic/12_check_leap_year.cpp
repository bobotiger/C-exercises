#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "Enter a year: ";
    cin >> year;    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        cout << year << " is a leap year.";
    else
        cout << year << " is not a leap year.";
    
    cout << endl;
    // 等价 if分支结构
    if(year % 4 == 0){
        if(year % 100 != 0){
            cout << year << " is a leap year.";
        } else {
            if(year % 400 == 0){
                cout << year << " is a leap year.";
            } else {
                cout << year << " is not a leap year.";
            }
        }
    } else {
        cout << year << " is not a leap year.";
    }
    
    return 0;
}