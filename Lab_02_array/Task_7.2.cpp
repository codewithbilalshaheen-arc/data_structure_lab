#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    int n, value;
    bool found = false;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> value;

    cout << "Found at indexes: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Element not found.";
    }
    cout << endl;

    return 0;
}
