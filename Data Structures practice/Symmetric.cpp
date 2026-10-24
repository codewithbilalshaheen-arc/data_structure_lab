#include<iostream>
using namespace std;

template<class T>
void mapSymmetric(T **a, int n, T *b)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			b[k++] = a[i][j];
}

template<class T>
T getSymmetric(T *b, int n, int i, int j)
{
	if (i < j) 
	{swap(i,j);}
	return b[i*(i+1)/2 + j];
}

template<class T>
void reverseSymmetric(T *b, int n, T **a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = getSymmetric(b, n, i, j);
}

int main()
{
	const int n = 5;
	int i, j;
	int data[n][n] = {{1,2,3,4,5},
	            {2,6,7,8,9},
	            {3,7,10,11,12},
	            {4,8,11,13,14},
	            {5,9,12,14,15}};
	int **a = new int*[n], **r = new int*[n];
	
	for (i = 0; i < n; i++) 
	{   a[i] = new int[n]; 
	    r[i] = new int[n]; 
	}
	int b[n*(n+1)/2];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) 
		{ 
			a[i][j] = data[i][j];
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	mapSymmetric(a, n, b);
	cout << endl << "1D array: ";
	for (i = 0; i < n*(n+1)/2; i++) 
		cout << b[i] << ", ";

	i = 1; j = 3;
	cout << endl << endl << "Element at (" << i << "," << j << ") = " << getSymmetric(b, n, i, j);
	i = 3; j = 1;
	cout << endl << "Element at (" << i << "," << j << ") = " << getSymmetric(b, n, i, j);

	reverseSymmetric(b, n, r);
	cout << endl << endl << "Reverse mapped matrix:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) 
		cout << r[i][j] << "\t";
		cout << endl;
	}

	for (i = 0; i < n; i++) { delete[] a[i]; delete[] r[i]; }
	delete[] a; delete[] r;
	return 0;
}