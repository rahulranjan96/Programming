#include <stack>
#include <iostream>
using namespace std;

stack<int> s1;
stack<int> s2;

void enqueue(int key)
{
	s1.push(key);
}
int dequeue()
{
	if(s1.empty()&&s2.empty())
	{
		cout<<"Error....\n";
		return -1;
	}
	if(s2.empty())
	{
		while(!s1.empty())
	{
	  s2.push(s1.top());
	  s1.pop();
	}
    }
	int key=s2.top();
	s2.pop();
	return key;
}
int main()
{
	int key,choice;
	while(1)
	{
		cout<<"1:Enqueue\n2:Dequeue\n3:Exit\nEnter Choice:";
        cin>>choice;
        switch(choice)
        {
        	case 1:cout<<"Enter the element to be enqueued:";
        	       cin>>key;
        	       enqueue(key);
        	       break;
        	case 2:key=dequeue();
        	       if(key!=-1)
        	       	cout<<key<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter valid choice.\n";
        }

	}
	return 0;
}