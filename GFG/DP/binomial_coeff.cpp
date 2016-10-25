#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int nCr(int n,int r)
{
	if(n<r)
		return 0;
	if(r==0||n==r)
		return 1;
	else return nCr(n-1,r-1)+nCr(n-1,r);
}
int min(int a,int b)
{
	if(a<=b)
		return a;
	else return b;
}
int nCr_dp(int n,int r)
{
	int mem[n+1][r+1];
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=min(i,r);j++)
	    {
	       if(i==j||j==0)
	       	mem[i][j]=1;
	       else mem[i][j]=mem[i-1][j-1]+mem[i-1][j];
		}
	return mem[n][r];
}
int main()
{
	int n,r;
	cout<<"Enter n and r:";
	cin>>n>>r;
	int ans=nCr_dp(n,r);
	cout<<ans<<endl;
	return 0;
}