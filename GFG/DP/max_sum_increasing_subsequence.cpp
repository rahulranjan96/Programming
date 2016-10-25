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
	int *miss=new int[n];
	miss[0]=a[0];
	for(int i=1;i<n;i++)
	{
		miss[i]=a[i];
		for(int j=0;j<=i-1;j++)
		{
			if(a[i]>a[j]&&miss[j]+a[i]>miss[i])
				miss[i]=a[i]+miss[j];
		}
	}
	int max=INT_MIN;
	for(int i=0;i<n;i++)
		if(miss[i]>max)
			max=miss[i];
    cout<<max<<endl;
    return 0;
}