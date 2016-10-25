#include <iostream>
#include <cstdlib>
using namespace std;

int length;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void max_heapify(int Arr[],int i)
{
	int l=2*i;
	int r=2*i+1;
	int largest=0;
	if(l<=length&&Arr[l]>Arr[i])
		l=largest;
	else largest=i;
	if(r<=length&&Arr[r]>Arr[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&Arr[i],&Arr[largest]);
		max_heapify(Arr,largest);
	}
}
int maximum(int Arr[ ])
    {
        return Arr[ 1 ];  //as the maximum element is the root element in the max heap.
    }
int extract_maximum (int Arr[ ])
{
    if(length == 0)
    {
cout<< "Can’t remove element as queue is empty";
        return -1;
    }
    int max = Arr[1];
    Arr[1] = Arr[length];
    length = length -1;
    max_heapify(Arr, 1);
    return max;
}
void increase_value (int Arr[ ], int i, int val)
{
    if(val < Arr[ i ])
    {
        cout<<"New value is less than current value, can’t be inserted" <<endl;
        return;
    }
    Arr[ i ] = val;
    while( i > 1 and Arr[ i/2 ] < Arr[ i ])
    {
        swap(&Arr[ i/2 ], &Arr[ i ]);
        i = i/2;
    }
}
void insert_value (int Arr[ ], int val)
{
    length = length + 1;
    Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
    increase_value(Arr, length, val);
}
int main()
{
	int *Arr=new int[100000];
	int c=0,data=0;
	length=0;
	while(1)
	{
		cout<<"1:Insert\n2:Extract Max\n3:Maximum\n4:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter number:";
			       cin>>data;
			       insert_value(Arr,data);
			       break;
			case 2:cout<<extract_maximum(Arr)<<endl;
			       break;
			case 3:cout<<maximum(Arr)<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Enter a valid choice\n";
			        break;
		}
	}
	return 0;
}