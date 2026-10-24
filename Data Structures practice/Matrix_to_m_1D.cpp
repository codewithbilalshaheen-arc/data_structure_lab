#include<iostream>
using namespace std;
int main()
{
	const int m=3, n=3;
	int i, j, a[m][n]={{1,2,3},{4,5,6},{7,8,9}};
	int **p; //int *ptr=&i, **p=&ptr;
	p=new int* [m] ; // p will point to an array of integer pointers
	cout<<p<<endl<<endl; // address
	for (i=0; i<m; i++)
	{
		cout<<p[i]<<endl; // i=0 (Strating value)
		p[i]=new int [n]; //p[i] will point to an array of integers
		cout<<p[i]<<endl; // starting address of pointer array
		for (j=0; j<n; j++)
		{
			p[i][j]=a[i][j];
			cout<<(p[i][j])<<endl;
		}
		cout<<endl;
	}

    for (i=0; i<m; i++)
		delete[] p[i];
	delete[] p;
    
	return 0;
}