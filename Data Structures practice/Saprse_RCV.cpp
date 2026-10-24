#include <iostream>
using namespace std;

int main()
{
	int m = 5, n = 5;
	int i, j, count = 0, a[m][n] = {{0, 0, 5, 2, 0},
									{0, 10, 0, 0, 9}, 
									{0, 2, 0, 12, 0}, 
									{0, 0, 3, 0, 0}, 
									{0, 0, 0, 0, 10}};

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
				count++;
		}
	}
	cout << endl << count;

	int ind = 0, v[count], r[count], c[count];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				v[ind] = a[i][j];
				r[ind] = i;
				c[ind++] = j;
			}
	cout << endl << endl;

    cout << "Values: ";
	for (i = 0; i < count; i++)
		cout << v[i] << "\t";
	cout << endl;

    cout << "Rows:   ";
	for (i = 0; i < count; i++)
		cout << r[i] << "\t";
	cout << endl;

    cout << "Column: ";
	for (i = 0; i < count; i++)
		cout << c[i] << "\t";
	cout << endl;
	return 0;
}