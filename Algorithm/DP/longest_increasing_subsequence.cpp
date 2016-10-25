#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int main()
{
	int n=0;
	cout<<"Enter the length of the array:";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter the elements of the array:";
	int *LIS=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	LIS[0]=1;
	for(int i=1;i<n;i++)
	{
		LIS[i]=1;
		for(int j=0;j<=i-1;j++)
		{
			if(a[i]>a[j]&&LIS[j]>=LIS[i])
				LIS[i]=LIS[j]+1;
		}
	}
	int max=INT_MIN;
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(LIS[i]>max)
			{
				max=LIS[i];
				index=i;
			}
	}
	cout<<max<<endl;
    int length=max;
    for(int i=n-1;i>=0;i--)
    {
    	if(LIS[i]==length)
    	{
    		cout<<a[i]<<" ";
    		length--;
    	}
    }
    cout<<endl;
    delete(a);
	delete(LIS);
	return 0;
}