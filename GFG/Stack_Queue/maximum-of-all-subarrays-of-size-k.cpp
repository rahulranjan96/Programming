#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;

//Naive Approach:O(nk)
/*int main() {
    int t;
    cin>>t;
    while(t--)
    {
	int n,k;
	cin>>n>>k;
	vector<int> a;
	int key;
	for(int i=0;i<n;i++)
	{
	    cin>>key;
	    a.push_back(key);
	}
	int max=INT_MIN;
	for(int i=0;i<n-k+1;i++)
	{
	    max=INT_MIN;
	    for(int j=i;j<i+k;j++)
	    {
	        if(a[j]>max)
	        max=a[j];
	    }
	    cout<<max<<" ";
	}
	cout<<endl;
    }
	return 0;
}*/
//Better Approach:O(n)
void max_k(int *a,int n,int k)
{
	deque<int> q;
	int i=0;
	for(i=0;i<k;i++)
	{
		while(!q.empty()&&a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	for(;i<n;i++)
	{
		cout<<a[q.front()]<<" ";
		while(!q.empty()&&q.front()<=i-k)
			q.pop_front();
		while(!q.empty()&&a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout<<a[q.front()];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		max_k(a,n,k);
		cout<<endl;
	}
}
