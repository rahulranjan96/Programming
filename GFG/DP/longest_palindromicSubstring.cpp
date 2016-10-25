#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

void lpstg(string s)
{
	int n=s.length();
	int mem[n][n];
	int max=INT_MIN;
	int start_id=0;
	int j=0;
	for(int i=0;i<n;i++)    //Palindrome of length 1
		{
			mem[i][i]=1;
			if(1>max)
			{
				max=1;
				start_id=i;
			}
		}
	for(int i=0;i<n-1;i++)  //Palindrome of length 2
		{
		  if(s[i]==s[i+1])
			{
				mem[i][i+1]=1;
				if(2>max)
				{
					max=2;
					start_id=i;
				}
			}
		  else mem[i][i+1]=0;
		}
    for(int k=2;k<n;k++)      //Palindrome of length >=3
    	for(int i=0;i<n-k;i++)
    	{
    	    j=k+i;
    		if(mem[i+1][j-1])
    		{
    			if(s[i]==s[j])
    				{
    					mem[i][j]=1;
    					if((j-i+1)>max)
    					{
    						max=j-i+1;
    						start_id=i;
    					}
    				}
    			else mem[i][j]=0;
    		}
    		else mem[i][j]=0;
    	}
    	for(int i=start_id;i<start_id+max;i++)
    		cout<<s[i];
    	cout<<endl;
 }
void lpstg_spaceEffi(string s)
{
	int n=s.length();
	int max=INT_MIN;
	int start,j,k;
	for(int i=0;i<n;i++)
	{
		j=i-1;
		k=i+1;
		if(1>max)
		{
		max=1;
	    start=i;
	    }
		while(j>=0&&k<=n-1)
		{
			if(s[j]==s[k])
			{
				if(k-j+1>max)
				{
					max=k-j+1;
					start=j;
				}
				j--;
				k++;
			}
			else break;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			j=i-1;
			k=i+2;
			if(2>max)
			{
				max=2;
				start=i;
			}
			while(j>=0&&k<=n-1)
			{
				if(s[j]==s[k])
				{
					if(k-j+1>max)
					{
						max=k-j+1;
						start=j;
					}
					j--;
					k++;
				}
				else break;
			}
		}
	}
	for(int i=start;i<start+max;i++)
		cout<<s[i];
	cout<<endl;
}
int main()
{
	string s;
	cout<<"Enter the string:";
	cin>>s;
	lpstg_spaceEffi(s);
}