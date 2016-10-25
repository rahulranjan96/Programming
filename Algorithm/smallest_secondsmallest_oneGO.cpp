#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int key;;
	int smallest,second_smallest;
	smallest=INT_MAX;
	second_smallest=INT_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>key;
		if(key<smallest)
		{
			second_smallest=smallest;
			smallest=key;
		}
		else if(key<second_smallest)
		{
			second_smallest=key;
		}
	}
	cout<<smallest<<" "<<second_smallest<<endl;
	return 0;
}