#include<iostream>
using namespace std;
int main()
{
	int i, j, k=0, b[20], 
	a[5][4]={{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16},
			{17,18,19,20}};
	for (i=0; i<5; i++)
		{
		for (j=0; j<4; j++)
			{
			cout<<a[i][j]<<"\t";
			b[k]=a[i][j];
			k++;
			}
		cout<<endl;	
		}
	cout<<endl;
	for (k=0; k<20; k++)
		cout<<b[k]<<", ";
	i=2; j=8;
	cout<<endl<<endl<<"Index: "<<i<<", "<<j;
	cout<<endl<<endl<<b[i*4+j];		
	return 0;
}
