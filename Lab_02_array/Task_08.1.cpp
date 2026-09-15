#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int size = 5, index, newVal;

    cout << "Current array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter index to update (0 to " << size - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return 1;
    }

    cout << "Enter new value: ";
    cin >> newVal;

    arr[index] = newVal;

    cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}