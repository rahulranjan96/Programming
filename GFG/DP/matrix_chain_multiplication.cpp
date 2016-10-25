#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int matrix_chain(int *order,int p,int q)
{
	if(p==q)
		return 0;
	int min=INT_MAX;
	int temp;
	for(int i=p;i<q;i++)
	{
		temp=matrix_chain(order,p,i)+matrix_chain(order,i+1,q)
		     +order[p-1]*order[i]*order[q];
		if(temp<min)
			min=temp;
	}
	return min;
}
int **mem;
int matrix_chain_dp_topDown(int *order,int p,int q)
{
  if(mem[p][q]!=-1)
  	return mem[p][q]
  if(p==q)
  	return 0;
  else
  {
  	int temp,min=INT_MAX;
    for(int i=p;i<q;i++)
    {
    	temp=matrix_chain_dp_topDown(order,p,i)+matrix_chain_dp_topDown(order,i+1,q)+order[p-1]*order[i]*order[q];
    	if(temp<min)
    		min=temp;
    }
    mem[p][q]=min;
    return mem[p][q];
  }
}
int main()
{
	int n;
	cout<<"Enter number of elements in order-array:";
	cin>>n;
	int *order=new int[n];
	cout<<"Enter elements of the order-array:";
	for(int i=0;i<n;i++)
		cin>>order[i];
	mem=new int*[n];
	for(int i=0;i<n;i++)
		mem[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mem[i][j]=-1;
	int ans=matrix_chain_dp_topDown(order,1,n-1);
	cout<<ans<<endl;
	return 0;
}