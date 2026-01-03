#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    int num1, num2;
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    return 0;
}

/**
 * Function to return GCD of a and b
 * Using Euclidean algorithm:
 * GCD(a, b) = GCD(b, a % b)
 * Base case: GCD(a, 0) = a
 * To prove correctness:
 * 1. If b divides a, then a % b = 0, so GCD(a, b) = GCD(b, 0) = b, which is correct.
 * 2. If b does not divide a, let a = bq + r (0 < r < b). Then GCD(a, b) = GCD(b, r).
 *   Since any common divisor of a and b must also divide r, the set of common divisors 
 * of (a, b) is the same as that of (b, r).
 *  Thus, GCD(a, b) = GCD(b, r).
 * This process continues until b becomes 0, at which point the GCD is a.
 * This algorithm is efficient with a time complexity of O(log(min(a, b))).
 * Example:
 * GCD(48, 18):
 * GCD(48, 18) = GCD(18, 48 % 18) = GCD(18, 12)
 * GCD(18, 12) = GCD(12, 18 % 12) = GCD(12, 6)
 * GCD(12, 6) = GCD(6, 12 % 6) = GCD(6, 0) = 6
 * Therefore, GCD(48, 18) = 6.
 *  
 */
int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}