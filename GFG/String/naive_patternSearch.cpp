#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

int main()
{
	char text[1000000],pat[1000];
	cout<<"Enter text string:";
	scanf("%[^\n]%*c",text);
	cout<<"Enter pattern string:";
	scanf("%[^\n]%*c",pat);
	int n=strlen(text);
	int m=strlen(pat);
	int i,j;
	for(i=0;i<=n-m;i++)   
		{
			for(j=0;j<m;j++)
			{
               if(pat[j]!=text[i+j])
               	break;
			}
			if(j==m)
				cout<<i<<endl;
		}
	return 0;
}