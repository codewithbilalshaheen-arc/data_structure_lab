#include <iostream>
using namespace std;
int main()
{
	const int n = 10;
	int i, j, mat[n][n] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 2, 0, 0, 0, 0, 0, 0, 0, 0}, {4, 2, 5, 0, 0, 0, 0, 0, 0, 0}, {5, 1, 8, 6, 0, 0, 0, 0, 0, 0}, {8, 1, 5, 8, 7, 0, 0, 0, 0, 0}, {7, 9, 8, 8, 6, 8, 0, 0, 0, 0}, {4, 7, 2, 7, 4, 4, 9, 0, 0, 0}, {5, 4, 7, 4, 5, 9, 8, 3, 0, 0}, {9, 4, 7, 4, 5, 7, 1, 5, 1, 0}, {3, 8, 3, 3, 7, 3, 2, 0, 2, 5}};
	int s = n / 2 * (1 + n);
	int c = 0, arr[s];

	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			arr[c++] = mat[i][j];

	cout << "\n\n\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}

	cout << endl;
	for (i = 0; i < s; i++)
		cout << arr[i] << ", ";

	cout << "\n\nEnter index i & j: ";
	cin >> i >> j;
	cout << mat[i][j] << endl;
	if (i < j)
		cout << 0;
	else
	{
		cout << "Index: " << s + j << endl;
		cout << arr[int(float(i) / 2 * (i + 1) + j)];
	}

	return 0;
}