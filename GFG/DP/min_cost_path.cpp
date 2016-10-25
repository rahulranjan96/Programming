#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int min3(int a,int b,int c)
{
	if(a<=b&&a<=c)
		return a;
	else if(b<=a&&b<=c)
		return b;
	else return c;
}
int min_cost_path(int **matrix,int row,int col)
{
	if(row<0||col<0)
		return INT_MAX;
	else if(row==0&&col==0)
		return matrix[row][col];
	else return matrix[row][col]+min3(min_cost_path(matrix,row,col-1),min_cost_path(matrix,row-1,col-1),min_cost_path(matrix,row-1,col));
}
int **mem;
int min_cost_path_dp_topDown(int **matrix,int row,int col)
{
	if(row<0||col<0)
		return INT_MAX;
	else if(row==0||col==0)
		return matrix[row][col];
	else if(mem[row][col]!=-1)
		return mem[row][col];
	else
	{
		mem[row][col]=matrix[row][col]+min3(min_cost_path(matrix,row,col-1),min_cost_path(matrix,row-1,col-1),min_cost_path(matrix,row-1,col));
	    return mem[row][col];
	}
}
int min_cost_path_dp_bottomUp(int **matrix,int row,int col)
{
	int mem[row+1][col+1];
	int sum=0;
	for(int i=0;i<=row;i++)
	{
      sum+=matrix[i][0];
      mem[i][0]=sum;
	}
	sum=0;
	for(int i=0;i<=col;i++)
	{
		sum+=matrix[0][i];
		mem[0][i]=sum;
	}
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++)
		{
			mem[i][j]=matrix[i][j]+min3(mem[i-1][j],mem[i][j-1],mem[i-1][j-1]);
		}
    return mem[row][col];		
}
int main()
{
	int n,m;
	cout<<"Enter number of rows:";
	cin>>n;
	cout<<"Enter number of columns:";
	cin>>m;
	int **matrix=new int*[n];
	for(int i=0;i<n;i++)
		matrix[i]=new int[m];
	cout<<"Enter the matrix:"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	int row,col;
	cout<<"Enter row and col number:";
	cin>>row>>col;
	mem=new int*[row+1];
	for(int i=0;i<=row;i++)
		mem[i]=new int[col+1];
	for(int i=0;i<=row;i++)
		for(int j=0;j<=col;j++)
			mem[i][j]=-1;
	int ans=min_cost_path_dp_bottomUp(matrix,row,col);
	cout<<ans<<endl;
	return 0;
}