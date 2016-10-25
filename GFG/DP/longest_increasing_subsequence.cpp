#include <iostream>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int n=0;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int *lis=new int[n];
        lis[0]=1;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<=i-1;j++)
            {
                if(a[i]>a[j]&&lis[j]+1>lis[i])
                lis[i]=lis[j]+1;
            }
        }
        int max=lis[0];
        for(int i=1;i<n;i++)
        {
            if(lis[i]>max)
            max=lis[i];
        }
        cout<<max<<endl;
        int length=max;
        for(int i=n-1;i>=0;i--)
        {
        	if(lis[i]==length)
        	{
        		cout<<a[i]<<" ";
        		length--;
        	}
        }
        cout<<endl;
    }
    return 0;
}