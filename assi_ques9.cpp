#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxDifference(const std::vector<int>& arr) {
    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());
    return maxElement - minElement;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n < 2) {
        cerr << "The array should have at least two elements." << endl;
        return 1;
    }

    vector<int> array(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
      cin >> array[i];
    }

    int maxDifference = findMaxDifference(array);
    cout << "The maximum difference between any two elements is: " << maxDifference << endl;

    return 0;
}
