#include <iostream>
using namespace std;

int main() {
    int cube[2][2][2];

    cout << "Enter 8 values for 2x2x2 array:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                cin >> cube[i][j][k];
            }
        }
    }

    cout << "\nDisplaying elements layer by layer:\n";
    for (int i = 0; i < 2; ++i) {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                cout << cube[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}