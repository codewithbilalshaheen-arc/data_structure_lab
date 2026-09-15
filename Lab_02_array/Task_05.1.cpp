#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5, pos, val;

    cout << "Array before insertion: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter element to insert: ";
    cin >> val;
    cout << "Enter target index position (0 to " << size << "): ";
    cin >> pos;

    if (pos < 0 || pos > size) {
        cout << "Invalid index!\n";
        return 1;
    }

    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;

    cout << "Array after insertion: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}