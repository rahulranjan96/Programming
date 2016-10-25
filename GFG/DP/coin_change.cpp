#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;


int coin_change(int *c,int n,int val)
{
	if(val==0)
		return 1;
	if(val<0)
		return 0;
	if(val>=1&&n<=0)
		return 0;
	else return coin_change(c,n-1,val)+coin_change(c,n,val-c[n-1]);
}

int **mem;
int coin_change_dp_topDown(int *c,int n,int val)
{
   if(val==0)
   	return 1;
   else if(val<0)
   	return 0;
   else if(val>=1&&n<=0)
   	return 0;
   else if(mem[n-1][val]!=-1)
   	return mem[n-1][val];
   else
    {
   	mem[n-1][val]=coin_change_dp_topDown(c,n-1,val)+coin_change_dp_topDown(c,n,val-c[n-1]);
    return mem[n-1][val];
    }
}

int coin_change_dp_bottomUp(int *c,int n,int val)
{
	int mem[n][val+1];
	for(int i=0;i<n;i++)
		mem[i][0]=1;
	int x,y;
    for(int i=0;i<n;i++)
    	for(int j=1;j<=val;j++)
    	{
    		if(j-c[i]>=0)
    			x=mem[i][j-c[i]];
    		else x=0;
    		if(i>=1)
    			y=mem[i-1][j];
    		else y=0;
    		mem[i][j]=x+y;
    	}
    return mem[n-1][val];
}
int main()
{
	int val,n;
	cout<<"Enter the value of Sum:";
	cin>>val;
    cout<<"Enter number of types of coins:";
    cin>>n;
    int *c=new int[n];
    cout<<"Enter the values of coins:";
    for(int i=0;i<n;i++)
    	cin>>c[i];
    mem=new int*[n];
    for(int i=0;i<n;i++)
  	 mem[i]=new int[val+1];
    for(int i=0;i<n;i++)
  	 for(int j=0;j<=val;j++)
  	      mem[i][j]=-1;
    int ans=coin_change_dp_bottomUp(c,n,val);
    cout<<ans<<endl;
    return 0;
}
