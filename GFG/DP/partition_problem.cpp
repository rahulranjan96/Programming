#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int isSubsetSum(int *set,int n,int sum)
{
	if(sum==0)
		return 1;
	else if(sum>0&&n==0)
		return 0;
	else if(sum<set[n-1])
		return isSubsetSum(set,n-1,sum);
	else return isSubsetSum(set,n-1,sum-set[n-1])|isSubsetSum(set,n-1,sum);
}
int **mem;
int isSubsetSum_dp_topDown(int *set,int n,int sum)
{
  if(mem[sum][n]!=-1)
  	return mem[sum][n];
  else if(sum==0)
  	return 1;
  else if(sum>0&&n==0)
  	return 0;
  else if(set[n-1]>sum)
  {
  	mem[sum][n]=isSubsetSum_dp_topDown(set,n-1,sum);
  	return mem[sum][n];
  }
  else
  {
  	mem[sum][n]=isSubsetSum_dp_topDown(set,n-1,sum-set[n-1])|isSubsetSum_dp_topDown(set,n-1,sum);
  	return mem[sum][n];
  }
}
int isSubsetSum_dp_bottomUp(int *set,int n,int sum)
{
	int **mem = new int*[sum+1];
	for(int i=0;i<=sum;i++)
		mem[i]=new int[n+1];
	for(int i=0;i<=n;i++)
		mem[0][i]=1;
	for(int i=1;i<=sum;i++)
		mem[i][0]=0;
	for(int i=1;i<=sum;i++)
		for(int j=1;j<=n;j++)
		{
			mem[i][j]=mem[i][j-1];
			if(set[j-1]<=i) 
		    mem[i][j]= mem[i-set[j-1]][j-1]|mem[i][j];
		}
	return mem[sum][n];
}
int isPartition(int *set,int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  	sum+=set[i];
  if(sum%2!=0)
  	return 0;
  else 
  	{   
  		sum=sum/2;
  		cout<<sum<<endl;
  		mem=new int*[sum+1];
  		for(int i=0;i<=sum;i++)
  			mem[i]=new int[n+1];
  		for(int i=0;i<=sum;i++)
  			for(int j=0;j<=n;j++)
  				mem[i][j]=-1;
  		return isSubsetSum_dp_bottomUp(set,n,sum);
  	}
}

int main()
{
	int n;
	cout<<"Enter number of elements in the set:";
	cin>>n;
	cout<<"Enter elements of the set:";
	int *set=new int[n];
	for(int i=0;i<n;i++)
		cin>>set[i];
	int ans=isPartition(set,n);
	if(ans)
		cout<<"True"<<endl;
	else cout<<"False"<<endl;
	return 0;
}