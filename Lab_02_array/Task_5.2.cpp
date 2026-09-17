#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    int n, value, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nCurrent Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nWhere do you want to insert the new element?" << endl;
    cout << "1. Beginning" << endl;
    cout << "2. Middle" << endl;
    cout << "3. End" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter value to insert: ";
    cin >> value;

    int position;

    if (choice == 1)
    {
        position = 0;
    }
    else if (choice == 2)
    {
        position = n / 2;
    }
    else if (choice == 3)
    {
        position = n;
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    // Shift elements to the right to make space
    for (int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    n++;

    cout << "\nArray after insertion:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
