#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int totalSum = 0;

    cout << "Enter elements for a 3x3 matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
            totalSum += matrix[i][j];
        }
    }

    cout << "\nSum of all elements in 3x3 matrix: " << totalSum << "\n";
    return 0;
}