#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void minHeapify(vector<int> *v,int i)
{
	int n=v->size();
	int lt=2*i+1;
	int rt=2*i+2;
	int smallest=0;
	if(lt<n&&((*v)[lt]<(*v)[i]))
		smallest=lt;
    else smallest=i;
    if(rt<n&&((*v)[rt]<(*v)[smallest]))
    	smallest=rt;
    if(smallest!=i)
    {
    	int temp=(*v)[i];
    	(*v)[i]=(*v)[smallest];
    	(*v)[smallest]=temp;
    	minHeapify(v,smallest);
    }
}
int getMin(vector<int> *v)
{
	if(!v->empty())
		return (*v)[0];
	else return -1;
}
int extractMin(vector<int> *v)
{
	if(!v->empty())
	{
	int key=(*v)[0];
	int temp=v->back();
	(*v)[0]=temp;
	v->pop_back();
	minHeapify(v,0);
	return key;
    }
    else return -1;
}
void decreaseKey(vector<int> *v,int key,int d)
{
	int flag=0;
	int i=0;
	for(i=0;i<v->size();i++)
	{
       if((*v)[i]==key)
       {
       	flag=1;
       	break;
       }
	}
	if(flag==0)
	{
		cout<<"Error...Key Not Found.\n"<<endl;
	}
	else
	{
		if(d>key)
		{
			cout<<"Error..New Value is greater than previous.\n";
		}
		else
		{
			(*v)[i]=d;
			while(i>0&&((*v)[(i-1)/2]>(*v)[i]))
			{
				int temp=(*v)[i];
				(*v)[i]=(*v)[(i-1)/2];
				(*v)[(i-1)/2]=temp;
				i=(i-1)/2;
			}
		}
	}
}
void insert(vector<int> *v,int key)
{
	v->push_back(key);
	int i=v->size()-1;
	while(i>0&&((*v)[(i-1)/2]>(*v)[i]))
	{
		int temp=(*v)[i];
		(*v)[i]=(*v)[(i-1)/2];
		(*v)[(i-1)/2]=temp;
		i=(i-1)/2;
	}
}

int main()
{
  vector<int> pQ;
  int key,c,d;
  while(1)
  {
  	cout<<"1:Get Minimum\n2:Extract Minimum\n3:Decrease Key\n4:Insert\n5:Exit\nEnter Choice:";
  	cin>>c;
  	switch(c)
  	{
  		case 1:key=getMin(&pQ);
  		       if(key!=-1)
  		       cout<<key<<endl;
  		       else cout<<"Error...Empty Heap\n";
  		       break;
  		case 2:key=extractMin(&pQ);
  		       if(key!=-1)
  		       cout<<key<<endl;
  		       else cout<<"Error...Empty Heap\n";
  		       break;
  		case 3:cout<<"Enter the key which you wanna decrease:";
  		       cin>>key;
  		       cout<<"Enter the value to which you want it to be decreased:";
  		       cin>>d;
  		       decreaseKey(&pQ,key,d);
  		       break;
  		case 4:cout<<"Enter the key to be inserted:";
  		       cin>>key;
  		       insert(&pQ,key);;
  		       break;
  		case 5:return 0;
  		default:cout<<"Please enter a valid choice\n";
  	}
  }
}