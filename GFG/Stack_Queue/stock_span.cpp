#include <iostream>
#include <stack>
using namespace std;

void func(int *prices,int *s,int n)
{
	stack<int> st;
	s[0]=1;
	st.push(0);
	for(int i=0;i<n;i++)
	{
		while(!st.empty()&&prices[st.top()]<=prices[i])
			st.pop();
		if(st.empty())
			s[i]=i+1;
		else s[i]=i-st.top();
		st.push(i);
	}
}

int main()
{
	int n=0;
	cin>>n;
	int prices[n];
	for(int i=0;i<n;i++)
		cin>>prices[i];
	int s[n];
	func(prices,s,n);
	for(int i=0;i<n;i++)
		cout<<s[i]<<" ";
	cout<<endl;
}