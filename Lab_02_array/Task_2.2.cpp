#include <iostream>
using namespace std;

int main()
{
    int arr[10];

    cout << "Enter 10 elements:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    // Reverse the array in place without using another array
    int start = 0;
    int end = 9;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "\nArray in Reverse Order:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
