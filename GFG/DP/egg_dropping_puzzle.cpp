#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int max(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}
int eggDrop(int n,int k)
{
	if(k==1||k==0)
		return k;
	if(n==1)
		return k;
	int min=INT_MAX,temp;
	for(int i=1;i<=k;i++)
	{
		temp=max(eggDrop(n-1,i-1),eggDrop(n,k-i));
		if(temp<min)
			min=temp;
	}
	return min+1;
}
int main()
{
	int n,k;
	cout<<"Enter number of eggs and number of floors:";
	cin>>n>>k;
	int ans=eggDrop(n,k);
	cout<<ans<<endl;
	return 0;
}