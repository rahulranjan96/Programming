#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &v,int i)
{
   int lt=2*i+1;
   int rt=2*i+2;
   int n=v.size();
   int largest=0;
   if(lt<n&&v[lt]>v[i])
   	largest=lt;
   else largest=i;
   if(rt<n&&v[rt]>v[largest])
   	largest=rt;
   if(largest!=i)
   {
   	int temp=v[i];
   	v[i]=v[largest];
   	v[largest]=temp;
   	maxHeapify(v,largest);
   }
}
void minHeapify(vector<int> &v,int i)
{
   int lt=2*i+1;
   int rt=2*i+2;
   int n=v.size();
   int smallest=0;
   if(lt<n&&v[lt]<v[i])
   	smallest=lt;
   else smallest=i;
   if(rt<n&&v[rt]<v[smallest])
   	smallest=rt;
   if(smallest!=i)
   {
   	int temp=v[i];
   	v[i]=v[smallest];
   	v[smallest]=temp;
   	minHeapify(v,smallest);
   }
}
int getMax(vector<int> &v)
{
  return v[0];
}
int extractMax(vector<int> &v)
{
  int temp=v[0];
  v[0]=v[v.size()-1];
  v.pop_back();
  maxHeapify(v,0);
  return temp;
}
void maxHeapinsert(vector<int> &v,int key)
{
   v.push_back(key);
   int n=v.size()-1;
   int temp;
   while(n>=1&&v[(n-1)/2]<v[n])
   {
     temp=v[n];
     v[n]=v[(n-1)/2];
     v[(n-1)/2]=temp;
     n=(n-1)/2;
   }
}
int getMin(vector<int> &v)
{
  return v[0];
}
int extractMin(vector<int> &v)
{
	int temp=v[0];
	v[0]=v[v.size()-1];
	v.pop_back();
	minHeapify(v,0);
	return temp;
}
void minHeapinsert(vector<int> &v,int key)
{
  v.push_back(key);
  int n=v.size()-1;
  int temp;
  while(n>=1&&v[(n-1)/2]>v[n])
  {
  	temp=v[n];
  	v[n]=v[(n-1)/2];
  	v[(n-1)/2]=temp;
  	n=(n-1)/2;
  }
}
int abs(int a)
{
	if(a>=0) return a;
    else return -1*a;
}
int main()
{
	vector<int> left;
	vector<int> right;
	int key1,key2;
	cout<<"Input:";
	cin>>key1;
	cout<<"Median:"<<key1<<endl;
	cout<<"Input:";
	cin>>key2;
	cout<<"Median:"<<(key1+key2)/2<<endl;
	if(key1>=key2)
		{
			maxHeapinsert(left,key2);
			minHeapinsert(right,key1);
		}
    else
    {
      maxHeapinsert(left,key1);
      minHeapinsert(right,key2);
    }
    int key;
	while(1)
	{
		cout<<"Input:";
		cin>>key;
		if(key>getMin(right))
			minHeapinsert(right,key);
		else maxHeapinsert(left,key);
		int lt=left.size();
		int rt=right.size();
		if(abs(lt-rt)>=2)
		{
			if(lt>rt)
			{
               int temp=extractMax(left);
               minHeapinsert(right,temp);
			}
			else
			{
               int temp=extractMin(right);
               maxHeapinsert(left,temp);
			}
		}
		lt=left.size();
		rt=right.size();
		if(lt==rt)
			cout<<"Median:"<<((getMin(right)+getMax(left))/2)<<endl;
		else if(lt>rt)
			cout<<"Median:"<<getMax(left)<<endl;
		else cout<<"Median:"<<getMin(right)<<endl;
	}
	delete(&left);
	delete(&right);
	return 0;
}
