#include <iostream>
Using namespace std;
int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sumOfDigits(num);
    cout << "The sum of the digits of " << num << " is: " << result << endl;
    return 0;
}
