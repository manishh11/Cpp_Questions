#include <iostream>
#include <unordered_set>
#include <algorithm>
Using namespace std;
int longestSubstring(string s) {
    int n = s.length();
    int maxLen = 0, i = 0, j = 0;
    unordered_set<char> charSet;

    while (j < n) {
        if (charSet.find(s[j]) == charSet.end()) {
            charSet.insert(s[j++]);
            maxLen = std::max(maxLen, j - i);
        } else {
            charSet.erase(s[i++]);
        }
    }

    return maxLen;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = longestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
