#include <iostream>
Using namespace std;
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    cout << "Enter the first number: ";
   cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    int gcd = findGCD(num1, num2);
    cout << "The greatest common divisor (GCD) of " << num1 << " and " << num2 << " is: " << gcd << endl;
    return 0;
}
