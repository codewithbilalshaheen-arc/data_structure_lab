#include<iostream>
using namespace std;
int main()
{
const int m=3, n=3;
int i, j, mat[m][n]={{1,2,3},{4,5,6},{7,8,9}};
int c=0, arr[m*n];	
for (i=0; i<m; i++)
	for (j=0; j<n; j++)
		arr[c++]=mat[i][j];

for (i=0; i<m; i++)
{
	for (j=0; j<n; j++)
		cout<<mat[i][j]<<"\t";
	cout<<endl;
}

cout<<endl;

for (i=0; i<m*n; i++)
	cout<<arr[i]<<", ";
	
cout<<"\n\nEnter index i & j: ";
cin>>i>>j;
cout<<mat[i][j]<<endl;
cout<<arr[i*n+j];
return 0;
}
