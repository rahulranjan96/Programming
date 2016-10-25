#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int isPal(char *s,int l,int h)
{
	int i=l,j=h;
	while(i<j)
	{
		if(s[i]!=s[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
int palpart(char *s,int l,int h)
{
  if(l==h) return 0;
  if(isPal(s,l,h)) return 0;
  int temp,min=INT_MAX;
  for(int i=l;i<h;i++)
  {
     temp=1+palpart(s,l,i)+palpart(s,i+1,h);
     if(temp<min) min=temp;
  }
  return min;
}
int main()
{
	char s[10000];
	scanf("%[^\n]%*c",s);
	int ans=palpart(s,0,strlen(s)-1);
	cout<<ans<<endl;
	return 0;
}