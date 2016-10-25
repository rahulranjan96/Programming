#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	int *hash=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		hash[i]=sum;
	}
	int max=hash[0];
	for(int i=1;i<n;i++)
		if(hash[i]>max)
			max=hash[i];
	int *hash1=new int[max];
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(hash1[hash[i]]==1)
		{
			flag=1;
			break;
		}
		else hash1[hash[i]]=1;
	}
	if(flag==1)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}