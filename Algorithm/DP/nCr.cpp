#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
using namespace std;


int main()
{
	int n=0,r=0,i=0,j=0;
	cout<<"Enter n and r:";
	cin>>n>>r;
	int **a=new int*[n+1];
	for(i=0;i<=n;i++)
		a[i]=new int[r+1];
	for(i=0;i<=n;i++)
		a[i][0]=1;
	a[1][1]=1;
	for(i=2;i<=n;i++)
		{
		for(j=1;j<=i&&j<=r;j++)
		 a[i][j]=a[i-1][j-1]+a[i-1][j];
	    if(i==n&&j==r)
	     break;
		}
	cout<<a[n][r]<<endl;
	for(i=0;i<=n;i++)
		delete(a[i]);
	return 0;
}