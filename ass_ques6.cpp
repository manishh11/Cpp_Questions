#include <iostream>
Using namespace std;
int factorial(int number) {
    if (number <= 1) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cerr << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }
    int result = factorial(num);
    cout << "The factorial of " << num << " is: " << result << endl;

    return 0;
}
