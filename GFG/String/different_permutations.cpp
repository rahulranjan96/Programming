#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

void maxheapify(char *s,int l,int h,int i)
{
	int lt=2*i+1;
	int rt=2*i+2;
	int largest=0;
	if(lt<=h&&s[lt]>s[i])
		largest=lt;
	else largest=i;
	if(rt<=h&&s[rt]>s[lt])
		largest=rt;
	if(largest!=i)
	{
		char c=s[largest];
		s[largest]=s[i];
		s[i]=c;
		maxheapify(s,l,h,largest);
	}
}

void maxheap(char *s,int l,int h)
{
	for(int i=(h-1)/2;i>=l;i--)
	  maxheapify(s,l,h,i);
}

void heapsort(char *s,int l,int h)
{
  maxheap(s,l,h);
  char c;
  for(int i=h;i>l;i--)
  {
    c=s[l];
    s[l]=s[i];
    s[i]=c;
    h--;
    maxheapify(s,l,h,l);
  }
}

void permutations(char *s)
{
  int n = strlen(s);
  heapsort(s,0,n-1);
  printf("%s\n",s);
  int index=0;
  int min,min_index=0;
  char c;
  while(1)
  {
  	for(int i=n-1;i>0;i--)
  	{
      if(s[i]>s[i-1])
      	{
      		index=i-1;
      		break;
      	}
  	}
    min=INT_MAX;
  	for(int i=index+1;i<n;i++)
  	{
  		if(s[i]>s[index])
  		{
  			if(s[i]<min)
  				{
  					min=s[i];
  					min_index=i;
  				}
  		}
  	}
  	if(min!=INT_MAX)
  	{
      c=s[index];
      s[index]=s[min_index];
      s[min_index]=c;
      if(index+1!=n-1)
      heapsort(s,index+1,n-1);
      printf("%s\n",s);
  	}
  	else break;
  }
}
int main()
{
	char s[100000];
	cout<<"Enter String:";
	cin>>s;
	permutations(s);
	return 0;
}