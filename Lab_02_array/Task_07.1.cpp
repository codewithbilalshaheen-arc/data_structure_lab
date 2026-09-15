#include <iostream>
using namespace std;

int main() {
    int arr[6] = {12, 45, 23, 67, 89, 34};
    int size = 6, key, foundIndex = -1;

    cout << "Enter target search value: ";
    cin >> key;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Element found at index: " << foundIndex << "\n";
    } else {
        cout << "Element Not Found.\n";
    }

    return 0;
}