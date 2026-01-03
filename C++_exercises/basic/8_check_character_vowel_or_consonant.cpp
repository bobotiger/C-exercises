#include <iostream>
using namespace std;

int main(){
    char ch;
    bool isLowercaseVowel, isUppercaseVowel;

    cout << "Enter an alphabet: ";
    cin >> ch;
    isLowercaseVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    isUppercaseVowel = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    if (!isalpha(ch))
        printf("Error! Non-alphabetic character entered.");
    else if (isLowercaseVowel || isUppercaseVowel)
        cout << ch << " is a vowel.";
    else
        cout << ch << " is a consonant.";
    return 0;
}