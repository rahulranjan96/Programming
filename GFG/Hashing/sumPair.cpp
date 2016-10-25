#include <iostream>

using namespace std;

int main()
{
	int n,sum;
	cin>>n;
	cin>>sum;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int max=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
	int *hash=new int[max];
	int temp;
	for(int i=0;i<n;i++)
	{
		temp=sum-a[i];
		if(temp>=0&&hash[temp]==1)
			cout<<a[i]<<" "<<temp<<endl;
		hash[a[i]]=1;
	}
	return 0;
}