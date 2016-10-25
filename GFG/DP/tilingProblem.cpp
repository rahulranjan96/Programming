#include <iostream>
using namespace std;

int numWays(int n)
{
	if(n<=2) return n;
	else return numWays(n-1)+numWays(n-2);
}
int main()
{
	int n;
	cin>>n;
	int ans=numWays(n);
	cout<<ans<<endl;
	return 0;
}