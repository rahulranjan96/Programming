#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	string s;
	cout<<"Enter the expression:";
	cin>>s;
	stack<int> st;
	int n=s.length();
	int a,b;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			st.push((int)s[i]-(int)'0');
		else if(s[i]=='+')
		{
          a=st.top();
          st.pop();
          b=st.top();
          st.pop();
          st.push(b+a);
		}
		else if(s[i]=='-')
		{
          a=st.top();
          st.pop();
          b=st.top();
          st.pop();
          st.push(b-a);
		}
		else if(s[i]=='*')
		{
          a=st.top();
          st.pop();
          b=st.top();
          st.pop();
          st.push(b*a);
		}
		else if(s[i]=='/')
		{
          a=st.top();
          st.pop();
          b=st.top();
          st.pop();
          st.push(b/a);
		}
	}
	cout<<st.top()<<endl;
	return 0;
}