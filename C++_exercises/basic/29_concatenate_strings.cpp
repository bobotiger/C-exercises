#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2, concatenated;
    cout << "Enter the first string: ";
    getline(cin, s1);
    cout << "Enter the second string: ";
    getline(cin, s2);
    concatenated = s1 + s2;
    cout << "Concatenated string: " << concatenated << endl;
    return 0;
}