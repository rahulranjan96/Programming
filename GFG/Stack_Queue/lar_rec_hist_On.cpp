#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int main()
{
	int n=0;
	cout<<"Enter number of bars:";
	cin>>n;
	int *hist=new int[n];
	cout<<"Enter height values:";
	for(int i=0;i<n;i++)
		cin>>hist[i];
	stack<int> st;
	st.push(0);
	int top,area,max_area=INT_MIN,i=0;
	for(i=1;i<n;i++)
	{
		
       if(hist[i]>=hist[st.top()])
       	st.push(i);
       else
       {
        while((!st.empty())&&hist[i]<hist[st.top()])
       	{  
       		top=st.top();
       		st.pop();
       	if(!st.empty())
       	{  
                  area=(i-st.top()-1)*hist[top];
       	}
       	else
       	{
       		area=i*hist[top];
       	}
       	if(area>max_area)
       		max_area=area;
            }
       st.push(i);
      }

	}
	while(!st.empty())
	{
		top=st.top();
       	st.pop();
       	if(!st.empty())
       	{
                 area=(i-st.top()-1)*hist[top];
       	}
       	else
       	{
       		area=i*hist[top];
       	}
       	if(area>max_area)
       		max_area=area;
	}
	cout<<max_area<<endl;
	return 0;
}