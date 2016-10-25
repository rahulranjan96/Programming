#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int max(int *a,int n,int i,int k)
{
   int max=i;
   for(int j=1;(i*k+j<=n)&&(j<=k);j++)
   {

   	if(a[max]<a[i*k+j])
   		max=i*k+j;
   }
   return max;
}

void max_heapify(int *a,int n,int i,int k)
{
  int largest = max(a,n,i,k);
  if(largest!=i)
  {
  swap(&a[largest],&a[i]);
  max_heapify(a,n,largest,k);
  }
}

void max_heap(int *a,int n,int k)
{
	//cout<<"Helllo";
	for(int i=(n-1)/2;i>=0;i--)
		{
			max_heapify(a,n,i,k);
			for(int i=0;i<=n;i++)
		      cout<<a[i]<<" ";
	          cout<<"\n";
		}
}

int main()
{
	int n;
	cout<<"Enter number of elements in heap:";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter the elements of the heap:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter K:";
	int k=0;
	cin>>k;
	max_heap(a,n-1,k);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}