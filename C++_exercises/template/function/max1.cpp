#include "max1.hpp"
#include <iostream>
#include <string>

int main(){
    int int1 = 10, int2 = 20;
    double double1 = 15.5, double2 = 10.5;
    std::string str1 = "apple", str2 = "banana";

    std::cout << "Max of " << int1 << " and " << int2 << " is: " 
        << ::max(int1, int2) << std::endl;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " 
        << ::max(double1, double2) << std::endl;
    std::cout << "Max of \"" << str1 << "\" and \"" << str2 << "\" is: \"" 
        << ::max(str1, str2) << "\"" << std::endl;

    return 0;
}