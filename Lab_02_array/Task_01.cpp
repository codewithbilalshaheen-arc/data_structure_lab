#include <iostream>
using namespace std;
int main() {
    int arr[10];
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    cout << "\nIndex\tValue\n";
    for (int i = 0; i < 10; ++i) 
    {
        cout << i << "\t" << arr[i] << "\n";
    }
    return 0;
}