#include <iostream>
using namespace std;

template <class T>
int mapSparse(T **a, int r, int c, int *R, int *C, T *V)
{
	int k = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] != 0)
			{
				R[k] = i;
				C[k] = j;
				V[k] = a[i][j];
				k++;
			}
	return k;
}

template <class T>
T getSparse(int *R, int *C, T *V, int cnt, int i, int j)
{
	for (int k = 0; k < cnt; k++)
		if (R[k] == i && C[k] == j)
			return V[k];
	return 0;
}

template <class T>
void reverseSparse(int *R, int *C, T *V, int cnt, int r, int c, T **a)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			a[i][j] = 0;
	for (int k = 0; k < cnt; k++)
		a[R[k]][C[k]] = V[k];
}

int main()
{
	const int r = 5, c = 6;
	int i, j;
	int data[r][c] = {  {0, 0, 3, 0, 0, 0},
					    {0, 7, 0, 0, 0, 0},
					    {0, 0, 0, 0, 9, 0},
					    {5, 0, 0, 0, 0, 0},
					    {0, 0, 0, 2, 0, 8}};

	int **a = new int *[r],
	    **m = new int *[r];

	for (i = 0; i < r; i++)
	{
		a[i] = new int[c];
		m[i] = new int[c];
	}
	int R[r * c], C[r * c], V[r * c];

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			a[i][j] = data[i][j];
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	int cnt = mapSparse(a, r, c, R, C, V);
	cout<< endl
		<< "Row\tCol\tValue" << endl;
	for (int k = 0; k < cnt; k++)
		cout << R[k] << "\t" << C[k] << "\t" << V[k] << endl;

	i = 2;
	j = 4;
	cout << endl
		<< "Element at (" << i << "," << j << ") = " << getSparse(R, C, V, cnt, i, j);
	i = 0;
	j = 0;
	cout << endl
		<< "Element at (" << i << "," << j << ") = " << getSparse(R, C, V, cnt, i, j);

	reverseSparse(R, C, V, cnt, r, c, m);
	cout << endl
		<< endl
		<< "Reverse mapped matrix:" << endl;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			cout << m[i][j] << "\t";
		cout << endl;
	}

	for (i = 0; i < r; i++)
	{
		delete[] a[i];
		delete[] m[i];
	}
	delete[] a;
	delete[] m;
	return 0;
}