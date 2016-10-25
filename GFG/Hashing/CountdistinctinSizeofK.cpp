#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map< int,int > hash;
	int dist_count=0;
	for(int i=0;i<k;i++)
	{
		if(hash[a[i]]==0)
			dist_count++;
		hash[a[i]]++;
	}
	cout<<dist_count<<endl;
	for(int i=k;i<n;i++)
	{
		if(hash[a[i-k]]==1)
			dist_count--;
		hash[a[i-k]]--;
		if(hash[a[i]]==0)
			dist_count++;
		hash[a[i]]++;
		cout<<dist_count<<endl;
	}
    return 0;
}