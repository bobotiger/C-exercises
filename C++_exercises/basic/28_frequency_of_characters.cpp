#include <iostream>
using namespace std;

int main(){
    string str = "C++ programming is fun";
    char checkChar = 'g';
    int count = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == checkChar){
            count++;
        }
    }
    cout << "The character '" << checkChar << "' appears " << count 
        << " times in the string." << endl;
    return 0;
}