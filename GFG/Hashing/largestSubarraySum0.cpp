#include <iostream>
#include <map>
#include <utility>
#include <climits>
using namespace std;
int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
int main()
{
	int n=0;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> hash;
	int sum=0;
	int max_length=INT_MIN;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(a[i]==0&&max_length==0)
			max_length=1;
		else if(sum==0)
			max_length=max(max_length,i+1);
		else if(hash.find(sum)==hash.end())
		  hash[sum]=i;
		else
		{
			int k=hash[sum];
			max_length=max(max_length,i-k);
		}
	}
	cout<<max_length<<endl;
	return 0;
}