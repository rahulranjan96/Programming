#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
char s[10][5]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void wfpd(int *a,int id,char *ans,int n)
{
	if(id==n)
	{
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<strlen(s[a[id]]);i++)
	{
		ans[id]=s[a[id]][i];
		wfpd(a,id+1,ans,n);
	}
}
void printWord(int *a,int n)
{
	char ans[n+1];
	ans[n]='\0';
	wfpd(a,0,ans,n);
}
int main()
{
	int n;
	cout<<"Enter number of digits in phone number:";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter digits of phone number:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	printWord(a,n);
	return 0;
}