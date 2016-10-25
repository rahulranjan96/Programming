#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements in array:";
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of the array:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	stack<int> st;
	st.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		while(!(st.empty())&&arr[i]>st.top())
		{
			cout<<st.top()<<"-->"<<arr[i]<<endl;
			st.pop();
		}
		st.push(arr[i]);
	}
	while(!st.empty())
	{
		cout<<st.top()<<"-->"<<"-1"<<endl;
		st.pop();
	}
	return 0;
}