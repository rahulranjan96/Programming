#include <iostream>
#include <climits>
using namespace std;

int minDen(int val,int *den,int n)
{
	if(val==0) return 0;
	if(val<0) return INT_MAX;
	if(val>0&&n<=0) return INT_MAX;
	int temp,min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(den[i]<=val)
		{
			temp=1+minDen(val-den[i],den,n);
			if(temp<min) min=temp;
		}
	}
	return min;
}
int main()
{
	int n,val;
	cin>>val>>n;
	int den[n];
	for(int i=0;i<n;i++) cin>>den[i];
    int ans=minDen(val,den,n);
	cout<<ans<<endl;
    return 0;
}
