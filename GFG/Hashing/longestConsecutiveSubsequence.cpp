#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <map>
#include <unordered_set>
#include <climits>
using namespace std;

int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	unordered_set <int> s;
	for(int i=0;i<n;i++)
		s.insert(a[i]);
	int temp,max_length=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i]-1)==s.end())
		{
			temp=a[i];
			while(s.find(temp)!=s.end())
			{
				temp++;
			}
			max_length=max(max_length,temp-a[i]);
		}
	}
	cout<<max_length<<endl;
	return 0;
}