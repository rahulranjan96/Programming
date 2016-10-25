#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int min3(int a,int b,int c)
{
   if(a<=b&&a<=c)
   	return a;
   else if(b<=a&&b<=c)
   	return b;
   else return c;
}
int min2(int a,int b)
{
	if(a<=b)
		return a;
	else return b;
}
int main()
{
	int n;
	cout<<"Enter the value of num:";
	cin>>n;
	int *a=new int[n+1];
	a[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			if(i%3==0)
				a[i]=1+min3(a[i-1],a[i/2],a[i/3]);
			else a[i]=1+min2(a[i-1],a[i/2]);
		}
		else
		{
			if(i%3==0)
				a[i]=1+min2(a[i-1],a[i/3]);
			else a[i]=1+a[i-1];
		}
	}
	cout<<a[n]<<endl;
	return 0;
}