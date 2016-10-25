#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int>a;
    int n;
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    int a1,b1,a2,b2;
    int flag1=0,flag2=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]%3==1&&flag1<2)
        {
            if(flag1==0)
            a1=a[i];
            else b1=a[i];
            flag1++;
        }
          if(a[i]%3==2&&flag2<2)
        {
            if(flag2==0)
            a2=a[i];
            else b2=a[i];
            flag2++;
        }
        
    }
    if(sum%3==0)
    {
        for(int i=n-1;i>=0;i--)
        cout<<a[i];
        cout<<endl;
    }
    else if(sum%3==1)
    {
        if(flag1!=0)
        {
           for(int i=n-1;i>=0;i--)
           { 
               if(a[i]!=a1)
               cout<<a[i]; 
           }
           cout<<"\n";
        }
        else if(flag2==2)
        {
            for(int i=n-1;i>=0;i--)
           { 
               if(a[i]!=a2&&a[i]!=b2)
               cout<<a[i]; 
           }
           cout<<"\n"; 
        }
        else cout<<"Not Possible\n";
    }
    else if(sum%3==2)
    {
        if(flag2!=0)
        {
            for(int i=n-1;i>=0;i--)
           { 
               if(a[i]!=a2)
               cout<<a[i]; 
           }
           cout<<"\n";
            
        }
        else if(flag1==2)
        {
             for(int i=n-1;i>=0;i--)
           { 
               if(a[i]!=a1&&a[i]!=b1)
               cout<<a[i]; 
           }
           cout<<"\n"; 
            
        }
        else cout<<"Not Possible"<<endl;
        
    }
    
    return 0;
    
}