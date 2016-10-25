#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
	int n;
	cin>>n;
	pair<int ,int > *pp=new pair<int,int>[n];
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		pp[i].first=x;
		pp[i].second=y;
	}
	map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		if(hash.find(pp[i].second)==hash.end())
			hash[pp[i].first]=pp[i].second;
		else
		{
			int temp=hash[pp[i].second];
			if(temp==pp[i].first)
				cout<<endl<<pp[i].first<<" "<<pp[i].second<<endl;
		}
	}
}