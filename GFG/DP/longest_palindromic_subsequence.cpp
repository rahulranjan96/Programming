#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int lps(string s,int p,int q)
{
	if(p==q)
		return 1;
	else if(s[p]==s[q]&&q==p+1)
		return 2;
	else if(s[p]==s[q])
		return 2+lps(s,p+1,q-1);
	else return max(lps(s,p,q-1),lps(s,p+1,q));
}
int **mem;
int lps_dp_topDown(string s,int p,int q)
{
	if(mem[p][q]!=-1)
		return mem[p][q];
   else if(p==q)
   		return 1;
   else if(s[p]==s[q]&&q==p+1)
   	 	return 2;
   else if(s[p]==s[q])
   	    {
   	    	mem[p][q]=2+lps_dp_topDown(s,p+1,q-1);
   	    	return mem[p][q];
   	    }
   else if(s[p]!=s[q])
   	    {
   	    	mem[p][q]=max(lps_dp_topDown(s,p+1,q),lps_dp_topDown(s,p,q-1));
   	    	return mem[p][q];
   	    }
}
int main()
{
	cout<<"Enter String:";
	string s;
	cin>>s;
	int n=s.length();
	mem=new int*[n];
	for(int i=0;i<n;i++)
		mem[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mem[i][j]=-1;
	int ans=lps_dp_topDown(s,0,n-1);
	cout<<ans<<endl;
}