#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> *Arr,int i,int j)
{
   int temp=(*Arr)[i];
   (*Arr)[i]=(*Arr)[j];
   (*Arr)[j]=temp;
}
void min_heapify(vector<int> *Arr,int i)
{
	int lt=2*i;
	int rt=2*i+1;
	int smallest=0;
	if(lt<=(Arr->size()-1)&&(*Arr)[lt]<(*Arr)[i])
		smallest=lt;
	else smallest=i;
	if(rt<=(Arr->size()-1)&&(*Arr)[rt]<(*Arr)[smallest])
		smallest=rt;
	if(smallest!=i)
	{
		swap(Arr,i,smallest);
		min_heapify(Arr,smallest);
	}
}
int min(vector<int> *Arr)
{
  return (*Arr)[1];
}
void insert(vector<int> *Arr,int data)
{
	Arr->push_back(data);
	int i=Arr->size()-1;
	while(i>1&&(*Arr)[i/2]>(*Arr)[i])
	{
		swap(Arr,i,i/2);
		i=i/2;
	}
}

void delet(vector<int> *Arr,int data)
{
	int i=0;
	for(i=1;i<Arr->size();i++)
	{
		if((*Arr)[i]==data)
			break;
	}
	swap(Arr,i,Arr->size()-1);
	Arr->pop_back();
	min_heapify(Arr,i);
	while(i>1&&(*Arr)[i/2]>(*Arr)[i])
	{
		swap(Arr,i,i/2);
		i=i/2;
	}

}
int main()

{
	vector<int> Arr;
	Arr.push_back(0);
	int data;
	int c;
	while(1)
	{
		cout<<"1:Insert\n2:Minimum\n3:Delete\n4:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
		  case 1:cin>>data;
		         insert(&Arr,data);
		         for(int i=1;i<Arr.size();i++) cout<<Arr[i]<<" ";
		         cout<<endl;
		         break;
		  case 2:cout<<min(&Arr)<<endl;
                 break;
          case 3:cin>>data;
                 delet(&Arr,data);
                 break;
          case 4:return 0;
		}
	}
  return 0;
}
