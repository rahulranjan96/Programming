#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
int editDistance_naive(string s1,int n,string s2,int m)
{
	if(n==0)
		return m;
	else if(m==0)
		 return n;
	else if(s1[n-1]==s2[m-1])
		return editDistance_naive(s1,n-1,s2,m-1);
	else return 1+min3(editDistance_naive(s1,n,s2,m-1),        //Insert
		        editDistance_naive(s1,n-1,s2,m),               //Remove
		        editDistance_naive(s1,n-1,s2,m-1)             //Replace
		               );
}
int **mem;
int editDistance_dp_topDown(string s1,int n,string s2,int m)
{
	if(mem[n][m]!=-1)
		return mem[n][m];
    if(n==0)
    	return m;
    else if(m==0)
    	return n;
    else if(s1[n-1]==s2[m-1])
    	mem[n][m]=editDistance_dp_topDown(s1,n-1,s2,m-1);
    else
    	mem[n][m]=1+min3(editDistance_dp_topDown(s1,n,s2,m-1),
    		             editDistance_dp_topDown(s1,n-1,s2,m),
    		             editDistance_dp_topDown(s1,n-1,s2,m-1)
    	             	);
    return mem[n][m];
}
int editDistance_dp_bottomUp(string s1,int n,string s2,int m)
{
	int mem[n+1][m+1];
	for(int i=0;i<=n;i++)
		mem[i][0]=i;
	for(int i=0;i<=m;i++)
		mem[0][i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
				mem[i][j]=mem[i-1][j-1];
			else 
			{
				mem[i][j]=1+min3(mem[i][j-1],
					            mem[i-1][j],
					            mem[i-1][j-1]
					           );
			}
		}
		return mem[n][m];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	mem=new int*[n+1];
	for(int i=0;i<=n;i++)
		mem[i]=new int[m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			mem[i][j]=-1;
	int count=editDistance_dp_bottomUp(s1,n,s2,m);
	cout<<count<<endl;
	return 0;
}