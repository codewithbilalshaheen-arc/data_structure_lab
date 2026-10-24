#include<iostream>
using namespace std;
int main()
{
const int n=3;
int i, j, mat[n][n]={{11,0,0},{0,5,0},{0,0,9}};
int c=0, arr[n];	
for (i=0; i<n; i++)
		arr[i]=mat[i][i];

for (i=0; i<n; i++)
{
	for (j=0; j<n; j++)
		cout<<mat[i][j]<<"\t";
	cout<<endl;
}

cout<<endl;

for (i=0; i<n; i++)
	cout<<arr[i]<<", ";
	
cout<<"\n\nEnter index i & j: ";
cin>>i>>j;
cout<<mat[i][j]<<endl;
if (i==j)
	cout<<arr[i];
else 
	cout<<0;
return 0;
}
