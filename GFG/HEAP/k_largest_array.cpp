#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
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
void insert(vector<int> *v,int key,int k)
{
  int n=v->size();
  if(n<k)
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
  else
  {
  	if(key>(*v)[0])
  		{
  			(*v)[0]=key;
  			minHeapify(v,0);
  		}
  }
}
void print(vector<int> *v)
{
	for(int i=0;i<v->size();i++)
		cout<<(*v)[i]<<" ";
	cout<<endl;
}
int main()
{
	vector<int> A;
	int k,n;
	cout<<"Enter the value of k:";
	cin>>k;
	int key,c;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter the element:";
			       cin>>key;
			       insert(&A,key,k);
			       break;
			case 2:n=A.size();
			       if(n<k)
			       	cout<<"Error...Not Enough Elements Read.\n";
			       else
			       	print(&A);
			       break;
			case 3:return 0;
			default:cout<<"Please enter a vald choice.\n";
		}
	}
	return 0;
}