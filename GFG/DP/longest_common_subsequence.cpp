#include <iostream>
#include <string>
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
int lcs_naive(string s1,int n,string s2,int m)
{
	if(n==0||m==0)
		return 0;
	else if(s1[n-1]==s2[m-1])
		return 1+lcs_naive(s1,n-1,s2,m-1);
	else return max(lcs_naive(s1,n-1,s2,m),lcs_naive(s1,n,s2,m-1));
}
int **mem;
int lcs_dp_topdown(string s1,int n,string s2,int m)
{
  if(mem[n][m]!=-1)
  	return mem[n][m];
  if(n==0||m==0)
  	return 0;
  else if(s1[n-1]==s2[m-1])
  {
  	mem[n][m]=1+lcs_dp_topdown(s1,n-1,s2,m-1);
  	return mem[n][m];
  }
  else
  {
  	mem[n][m]=max(lcs_dp_topdown(s1,n-1,s2,m),lcs_dp_topdown(s1,n,s2,m-1));
  	return mem[n][m];
  }
}
int lcs_dp_bottomup(string s1,int n,string s2,int m)
{
	int mem[n+1][m+1];
	for(int i=0;i<=n;i++)
		mem[i][0]=0;
	for(int i=0;i<=m;i++)
		mem[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
				mem[i][j]=1+mem[i-1][j-1];
			else mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
		}
		int length=mem[n][m];
		char s[length+1];
		s[length]='\0';
		length=length-1;
		int i=n,j=m;
		while(i>0&&j>0)
		{
			if(s1[i-1]==s2[j-1])
			{
				s[length--]=s1[i-1];
				i--;
				j--;
			}
			else if(mem[i-1][j]>mem[i][j-1])
				i--;
			else j--;
		}
		cout<<s<<endl;
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
   int length=lcs_dp_bottomup(s1,n,s2,m);
   cout<<length<<endl;
   for(int i=0;i<=n;i++)
   	delete(mem[i]);
   return 0;
}