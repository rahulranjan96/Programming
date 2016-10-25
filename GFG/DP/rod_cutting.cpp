#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int max_profit(int *cost,int n)
{
	if(n<=0) return 0;
	int max=INT_MIN,temp;
	for(int i=1;i<=n;i++)
	{
      temp=cost[i]+max_profit(cost,n-i);
      if(temp>max)
      	max=temp;
	}
	return max;
}
int *mem;
int max_profit_dp_topBottom(int *cost,int n)
{
	if(n<=0)
		return 0;
	else if(mem[n]!=-1)
		return mem[n];
	else
	{
		int temp=0,max=INT_MIN;
		for(int i=1;i<=n;i++)
		{
           temp=cost[i]+max_profit_dp_topBottom(cost,n-i);
           if(temp>max)
           	max=temp;
		}
		mem[n]=max;
		return mem[n];
	}
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}
int max_profit_dp_bottomUp(int *cost,int n)
{
	if(n<=0)
		return 0;
	int mem[n+1];
	mem[0]=0;
	int temp=0,max=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		max=INT_MIN;
		for(int j=1;j<=i;j++)
		{
          temp=cost[j]+mem[i-j];
          if(temp>max)
          	max=temp;
		}
		mem[i]=max;
	}
	return mem[n];
}
int main()
{
	int n;
	cout<<"Enter length of rod:";
	cin>>n;
	int *cost=new int[n+1];
	cout<<"Enter cost of lengths of rod:";
	for(int i=1;i<=n;i++)
		cin>>cost[i];
	mem=new int[n+1];
	for(int i=0;i<=n;i++)
		mem[i]=-1;
	mem[0]=0;
	int ans=max_profit_dp_bottomUp(cost,n);
	cout<<ans<<endl;
	return 0;
}