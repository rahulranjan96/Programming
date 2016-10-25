#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
using namespace std;

int main()
{
	int n,i;
	cout<<"Enter the n for the fibonacci number:";
	cin>>n;
	if(n==0||n==1)
		cout<<"1"<<endl;
	else
	{
	int *a=new int[n+1];
	a[0]=1;
	a[1]=1;
	for(i=2;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
	cout<<a[n]<<endl;
	delete(a);
    }
	return 0;
}