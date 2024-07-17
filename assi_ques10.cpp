#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isAlphabetic(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) { >
            return false;
        }
    }
    return true;
}

int main() {
    string userInput;

    cout << "Enter a string: ";
   getline(cin, userInput);

   cout << "The string contains only alphabetic characters: ";
    cout << (isAlphabetic(userInput) ? "True" : "False") << endl;

    return 0;
}
