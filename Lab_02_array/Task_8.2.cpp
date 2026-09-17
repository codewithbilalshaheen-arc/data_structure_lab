#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nBefore:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = 0;
        }
    }

    cout << "\nAfter:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
