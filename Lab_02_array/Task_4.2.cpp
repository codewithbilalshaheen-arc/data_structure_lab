#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    int evenSum = 0;
    int oddSum = 0;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenSum = evenSum + arr[i];
        }
        else
        {
            oddSum = oddSum + arr[i];
        }
    }

    cout << "\nSum of Even Elements = " << evenSum << endl;
    cout << "Sum of Odd Elements = " << oddSum << endl;

    delete[] arr;
    return 0;
}
