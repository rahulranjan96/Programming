#include <iostream>
#include <utility>
#include <map>
using namespace std;


int main()
{
	int k=0,n=0;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *freq=new int[k];
	for(int i=0;i<n;i++)
		freq[a[i]%k]++;
	int flag=0;
	for(int i=0;i<k;i++)
	{
		if(freq[i]!=0)
		{
			if(i==0&&freq[i]%2!=0)
			{
				flag=1;
				break;
			}
			else if(freq[i]!=freq[k-i])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		cout<<"Not Possible\n";
	else cout<<"Possible\n";
	return 0;
}