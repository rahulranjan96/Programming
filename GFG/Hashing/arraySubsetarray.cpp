#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main()
{
	int n,m;
	cout<<"Enter n and m:";
	cin>>n>>m;
	int flag=0;
	int *a=new int[n];
	int *b=new int[m];
	cout<<"Enter the values of array 'a':";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the values of array 'b':";
	for(int i=0;i<m;i++)
		cin>>b[i];
	int max=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max) max=a[i];
	int *hash=new int[max];
	for(int i=0;i<n;i++)
		hash[a[i]]=1;
	for(int i=0;i<m;i++)
		{
			if(hash[b[i]]==0)
			{
				flag=1;
				break;
			}
		}
	if(flag==1)
		cout<<"Not a Subset\n";
	else cout<<"Is a Subset\n";
	return 0;
}