#include <iostream>
using namespace std;
int main()
{
	const int n = 10;
	int i, j, mat[n][n] = { {1, 2, 0, 0, 0, 0, 0, 0, 0, 0},
	                        {3, 2, 5, 0, 0, 0, 0, 0, 0, 0}, 
							{0, 2, 5, 9, 0, 0, 0, 0, 0, 0}, 
							{0, 0, 8, 6, 8, 0, 0, 0, 0, 0}, 
							{0, 0, 0, 8, 7, 2, 0, 0, 0, 0}, 
							{0, 0, 0, 0, 6, 8, 1, 0, 0, 0}, 
							{0, 0, 0, 0, 0, 4, 9, 1, 0, 0}, 
							{0, 0, 0, 0, 0, 0, 8, 3, 4, 0}, 
							{0, 0, 0, 0, 0, 0, 0, 5, 1, 3}, 
							{0, 0, 0, 0, 0, 0, 0, 0, 2, 5}};

	int c = 0, arr[3 * n - 2];

	for (i = 0; i < n; i++)
		arr[c++] = mat[i][i];

	for (i = 0; i < n - 1; i++)
		arr[c++] = mat[i][i + 1];

	for (i = 0; i < n - 1; i++)
		arr[c++] = mat[i + 1][i];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}

	cout << endl;
	for (i = 0; i < 3 * n - 2; i++)
		cout << arr[i] << ", ";

	cout << "\n\nEnter index i & j: ";
	cin >> i >> j;
	cout << mat[i][j] << endl;
	if (i == j)
		cout << arr[i];
	else if (i + 1 == j)
		cout << arr[n + j];
	else if (i = j + 1)
		cout << arr[2 * n - 1 + j];
	else
		cout << 0;
	return 0;
}