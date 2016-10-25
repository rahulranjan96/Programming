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
int knap_sack(int W,int *w,int *val,int n)
{
   if(W==0||n==0) return 0;
   else if(w[n-1]>W) return knap_sack(W,w,val,n-1);
   else return max(val[n-1]+knap_sack(W-w[n-1],w,val,n-1),knap_sack(W,w,val,n-1));
}
int **mem;
int knap_sack_dp_topDown(int W,int *w,int *val,int n)
{
  if(W==0||n==0)
  	return 0;
  else if(mem[W][n]!=-1)
  	return mem[W][n];
  else if(W<w[n-1])
  {
  	mem[W][n]=knap_sack_dp_topDown(W,w,val,n-1);
    return mem[W][n];
  }
  else
  {
  	mem[W][n]=max(val[n-1]+knap_sack_dp_topDown(W-w[n-1],w,val,n-1),knap_sack_dp_topDown(W,w,val,n-1));
  	return mem[W][n];
  }
}
int knap_sack_dp_bottomUp(int W,int *w,int *val,int n)
{
	int mem[W+1][n+1];
	for(int i=0;i<=W;i++)
		mem[i][0]=0;
	for(int i=0;i<=n;i++)
		mem[0][i]=0;
	for(int i=1;i<=W;i++)
		for(int j=1;j<=n;j++)
		{
            if(i<w[j-1])
				mem[i][j]=mem[i][j-1];
			else mem[i][j]=max(val[j-1]+mem[i-w[j-1]][j-1],mem[i][j-1]);
		}
		return mem[W][n];
}
int main()
{
	int W,n;
	cout<<"Enter maximum weight allowed:";
	cin>>W;
	cout<<"Enter number of objects:";
	cin>>n;
	int *w=new int[n];
	int *val=new int[n];
	cout<<"Enter weights of n-objects:";
	for(int i=0;i<n;i++)
		cin>>w[i];
	cout<<"Enter values of n-objects:";
	for(int i=0;i<n;i++)
		cin>>val[i];
	mem=new int*[W+1];
	for(int i=0;i<=W;i++)
		mem[i]=new int[n+1];
	for(int i=0;i<=W;i++)
		for(int j=0;j<=n;j++)
			mem[i][j]=-1;
	for(int i=0;i<=W;i++)
		mem[i][0]=0;
	for(int i=0;i<=n;i++)
		mem[0][i]=0;
	int ans=knap_sack_dp_bottomUp(W,w,val,n);
	cout<<ans<<endl;
	return 0;
}

