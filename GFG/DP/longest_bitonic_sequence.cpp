#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;


int main()
{
	int n;
	cout<<"Enter number of elements in the array:";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter elements of the array:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *lis=new int[n];
	int *lds=new int[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<=i-1;j++)
		{
			if(a[i]>a[j]&&lis[j]+1>lis[i])
				lis[i]=lis[j]+1;
		}
	}
	lds[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		lds[i]=1;
		for(int j=n-1;j>=i-1;j--)
		{
			if(a[i]>a[j]&&lds[j]+1>lds[i])
				lds[i]=lds[j]+1;
		}
	}
	int max=INT_MIN;
  for(int i=0;i<n;i++)
  {
    if((lis[i]+lds[i]-1)>max)
    	max=lis[i]+lds[i]-1;
  }
   cout<<max<<endl;
   return 0;	
}