#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
bool isSubsetSum(int *set,int n,int sum)
{
	if(sum==0)
		return true;
	else if(n==0&&sum>0)
		return false;
	else if(set[n-1]>sum)
		return isSubsetSum(set,n-1,sum);
	else return isSubsetSum(set,n-1,sum-set[n-1])||isSubsetSum(set,n-1,sum);
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
  	    mem[sum][n]=isSubsetSum_dp_topDown(set,n-1,sum)|isSubsetSum_dp_topDown(set,n-1,sum-set[n-1]);
  	    return mem[sum][n];
    }
}

int main()
{
   int n,sum=0;
   cout<<"Enter number of elements in the set:";
   cin>>n;
   int *set=new int[n];
   cout<<"Enter elements of the set:";
   for(int i=0;i<n;i++)
   cin>>set[i];
   cout<<"Enter sum:";
   cin>>sum;
   mem=new int*[sum+1];
   for(int i=0;i<=sum;i++)
   	mem[i]=new int[n+1];
   for(int i=0;i<=sum;i++)
   	for(int j=0;j<=n;j++)
   		mem[i][j]=-1;
   int ans=isSubsetSum_dp_topDown(set,n,sum);
   if(ans)
   	cout<<"True"<<endl;
   else cout<<"False"<<endl;
   return 0;	
}