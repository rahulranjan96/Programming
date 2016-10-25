#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> *v,int i)
{
    int n=v->size();
    int lt=2*i+1;
    int rt=2*i+2;
    int smallest=0;
    if(lt<n&&(*v)[lt]<(*v)[i])
    smallest=lt;
    else smallest=i;
    if(rt<n&&(*v)[rt]<(*v)[smallest])
    smallest=rt;
    if(smallest!=i)
    {
        int temp=(*v)[i];
        (*v)[i]=(*v)[smallest];
        (*v)[smallest]=temp;
        minHeapify(v,smallest);
    }
}
void minHeap(vector<int>* v)
{
    int n=v->size()-1;
    for(int i=(n-1)/2;i>=0;i--)
    {
        minHeapify(v,i);
    }
}
int extractMin(vector<int> *v)
{
    int key=(*v)[0];
    (*v)[0]=v->back();
    v->pop_back();
    minHeapify(v,0);
    return key;
}
void insert(vector<int> *v,int key)
{
    v->push_back(key);
    int i=v->size()-1;
    int temp=0;
    while(i>0&&(*v)[(i-1)/2]>(*v)[i])
    {
        temp=(*v)[i];
        (*v)[i]=(*v)[(i-1)/2];
        (*v)[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}
int main() {
	int t=0;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> heap;
	    int key;
	    for(int i=0;i<n;i++)
	    {
	        cin>>key;
	        heap.push_back(key);
	    }
	    minHeap(&heap);
	    int a,b;
        int sum=0;
	    while(heap.size()>1)
	    {
	        a=extractMin(&heap);
	        b=extractMin(&heap);
            sum=sum+a+b;
            //cout<<a<<" "<<b<<endl;
	        insert(&heap,a+b);
	    }
	    cout<<sum<<endl;
	    
	}
	return 0;
}