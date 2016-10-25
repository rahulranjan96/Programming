#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
	int n,sum=0;
	cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map< int,pair<int,int> > hash;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
          sum=a[i]+a[j];
          if(hash.find(sum)==hash.end())
          	hash[sum]=make_pair(i,j);
          else
          {
          	pair<int,int> pp=hash[sum];
          	cout<<a[pp.first]<<" "<<a[pp.second]<<endl<<a[i]<<" "<<a[j]<<endl;
          	break;
          }
		}
		return 0;
}