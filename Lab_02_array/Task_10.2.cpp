#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][2];
    int sum = 0;

    cout << "Enter 8 elements:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "\nThree-Dimensional Array:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "\nLayer " << i + 1 << ":" << endl;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << arr[i][j][k] << "\t";
                sum = sum + arr[i][j][k];
            }
            cout << endl;
        }
    }

    cout << "\nSum of all elements = " << sum << endl;

    return 0;
}
