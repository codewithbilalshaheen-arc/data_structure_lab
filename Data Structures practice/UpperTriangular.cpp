#include <iostream>
using namespace std;

template <class T>
void mapUpper(T **a, int n, T *b)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			b[k++] = a[i][j];
}

template <class T>
T getUpper(T *b, int n, int i, int j)
{
	if (i <= j)
		return b[i * n - i * (i - 1) / 2 + (j - i)];
	return 0;
}

template <class T>
void reverseUpper(T *b, int n, T **a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = getUpper(b, n, i, j);
}

int main()
{
	const int n = 5;
	int i, j;
	int data[n][n] = {{1, 2, 3, 4, 5},
					  {0, 6, 7, 8, 9},
					  {0, 0, 10, 11, 12},
					  {0, 0, 0, 13, 14},
					  {0, 0, 0, 0, 15}};

	int **a = new int *[n], **r = new int *[n];

	for (i = 0; i < n; i++)
	{
		a[i] = new int[n];
		r[i] = new int[n];
	}
	int b[n * (n + 1) / 2];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = data[i][j];
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	mapUpper(a, n, b);
	cout << endl
		 << "1D array: ";
	for (i = 0; i < n * (n + 1) / 2; i++)
		cout << b[i] << ", ";

	i = 1;
	j = 3;
	cout << endl
		 << endl
		 << "Element at (" << i << "," << j << ") = " << getUpper(b, n, i, j);
	i = 3;
	j = 1;
	cout << endl
		 << "Element at (" << i << "," << j << ") = " << getUpper(b, n, i, j);

	reverseUpper(b, n, r);
	cout << endl
		 << endl
		 << "Reverse mapped matrix:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << r[i][j] << "\t";
		cout << endl;
	}

	for (i = 0; i < n; i++)
	{
		delete[] a[i];
		delete[] r[i];
	}
	delete[] a;
	delete[] r;
	return 0;
}