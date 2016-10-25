
#include<iostream>
using namespace std;


int min(int a,int b)
{
	if(a<=b)
		return a;
	else return b;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char *s=new char[n+1];
		cin>>s;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		unsigned long long int sum=0;
		int temp1=0,temp2=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
					if(i==0)
				{
					for(int j=i;j<n;j++)
					{
						if(s[j]=='1')
							break;
						else if(s[j]=='0')
							s[j]='1';
					}
                   sum=sum+a[j]-a[i];
                   i+=j-i-1;
				}
				else
				{
                   temp1=a[i]-a[i-1];
                   temp2=a[i+1]-a[i];
                   if(temp1<temp2)


				}

			}

		}
		/*int *zero=new int[n];
		int n0=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
				zero[n0++]=i;
		}
        int x,y;
        unsigned long long int sum=0;
        for(int i=0;i<n0;i++)
        {
          x=zero[i];
          y=-1;
          for(int j=x+1;j<n;j++)
           {
             if(s[j]=='1')
              {
              	y=j;
              	break;
              }
          	}
          if(x==0)
          {
          	sum=sum+a[y]-a[x];
          }
          else
          {
          	if(y!=-1)
          		sum=sum+min(a[y]-a[x],a[y-1]-a[x-1]);
          	else
                {
                	sum = sum + a[n-1]-a[x-1];
                	break;
                }
          }
          i = i + y - x -1;
        }
        */
        cout<<sum<<"\n";
     	}
	return 0;
}