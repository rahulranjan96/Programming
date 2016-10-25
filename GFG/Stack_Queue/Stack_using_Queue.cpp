#include <iostream>
#include <queue>
using namespace std;

void push(queue<int> *q1,queue<int> *q2,int key)
{
  q1->push(key);
}
int pop(queue<int> *q1,queue<int> *q2)
{
	if(q1->empty())
	{
		cout<<"Error..Empty Stack\n";
		return -1;
	}
	else
	{
		while(q1->size()!=1)
		{
			q2->push(q1->front());
			q1->pop();
		}
		int ans=q1->front();
		q1->pop();
		while(!q2->empty())
		{
			q1->push(q2->front());
			q2->pop();
		}
		return ans;
	}
}

int main()
{
	int c,key;
	queue<int> q1;
	queue<int> q2;
	while(1)
	{
		cout<<"1:Push\n2:Pop\n3:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter key to be pushed:";
			       cin>>key;
			       push(&q1,&q2,key);
			       break;
			case 2:key=pop(&q1,&q2);
			       if(key!=-1)
			       cout<<key<<endl;
			       break;
			case 3:return 0;
			default:cout<<"Please enter valid choice\n";
		}
	}
	return 0;
}