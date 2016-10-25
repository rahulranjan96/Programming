#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack<char> st;
	string s;
	cout<<"Enter the string:";
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
		st.push(s[i]);
	for(int i=0;i<n;i++)
	{
		s[i]=st.top();
		st.pop();
	}
	cout<<"Reversed String:"<<s<<endl;
	return 0;
}