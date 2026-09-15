#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5, pos;

    cout << "Array before deletion: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter index position to delete (0 to " << size - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= size) {
        cout << "Invalid index!\n";
        return 1;
    }

    for (int i = pos; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Array after deletion: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}