#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1,s2;
    cout << "Enter the first string: ";
    getline(cin,s1);
    s2 = s1; // Copying s1 to s2
    cout << "s2 = " << s2 << endl;
    return 0;
}