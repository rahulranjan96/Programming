#include <iostream>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k=0;
	while(1)
	{
		cin>>k;
		int low=0;
		int high=n-1;
		int mid=0;
		int pivot=0;
		int next,prev;
		while(lt<=high)
		{
			if(a[low]<=a[high])
			{
				pivot=low;
				break;
			}
           next=(mid+1)%n;
           prev=(mid-1+n)%n;
			mid=(low+high)/2;
			if(a[next]>=a[mid]&&a[prev]>=a[mid])
			{
				pivot=mid;
				break;
			}
			else if(a[mid]<=a[high])
				high=mid-1;
			else if(a[mid]>=a[low])
				low=mid+1;
		}
		if(key<=a[high]&&key>=a[pivot])
		{
           
		}
		prev=(pivot-1+n)%n;
		if(key>=a[low]&&key<=a[prev])
		{

		}
	}
}