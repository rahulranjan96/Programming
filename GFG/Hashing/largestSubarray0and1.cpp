#include <iostream>
#include <utility>
#include <map>
#include <climits>
using namespace std;
int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> hash;
	int sum=0;
	int max_length=0;
	for(int i=0;i<n;i++)
   	{
   		if(a[i]==1) sum+=1;
   		else sum-=1;
		if(sum==0)
		{
			max_length=max(max_length,i+1);
		}
		else
		{
			if(hash.find(sum)!=hash.end())
			{
				max_length=max(max_length,i-hash[sum]);
			}
			else hash[sum]=i;
		}
	}
	cout<<max_length<<endl;
    return 0;
}