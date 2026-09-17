#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    int n, value;
    int foundIndex = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value to search and delete: ";
    cin >> value;

    // Find the first occurrence
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        cout << "Value not found in the array." << endl;
    }
    else
    {
        // Shift elements to the left to remove the found element
        for (int i = foundIndex; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;

        cout << "\nArray after deletion:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
