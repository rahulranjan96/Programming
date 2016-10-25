#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;
typedef struct 
{
	int key;
	int row;
	int col;
}node;
void minHeapify(node *a,int i,int k)
{
	int lt=2*i+1;
	int rt=2*i+2;
	int smallest=0;
	if(lt<k&&a[lt].key<a[i].key)
		smallest=lt;
	else smallest=i;
	if(rt<k&&a[rt].key<a[smallest].key)
		smallest=rt;
	if(smallest!=i)
	{
		node temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minHeapify(a,smallest,k);
	}
}
void minHeap(node *a,int k)
{
	for(int i=(k-1)/2;i>=0;i--)
		minHeapify(a,i,k);
}

int main()
{
	int n,k;
	node temp;
	cin>>n>>k;
	int **a=new int*[k];
	for(int i=0;i<k;i++)
		a[i]=new int[n];
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	int *ans=new int[n*k];
	node *heap=new node[k];
	for(int i=0;i<k;i++)
	 {
	 	heap[i].key=a[i][0];
	 	heap[i].row=i;
	 	heap[i].col=0;
	 }
	minHeap(heap,0,k);
	int row,col;
	for(int i=0;i<n*k;i++)
	{
		temp=heap[0];
        ans[i]=temp.key;
        row=temp.row;
        col=temp.col;
        col++;
        if(col<n)
        {
        heap[0].key=a[row][col];
        heap[0].row=row;
        heap[0].col=col;
        }
        else
        {
        	heap[0].key=INT_MAX;
        }
        minHeapify(heap,0,k); 
    }
    for(int i=0;i<n*k;i++)
    	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}