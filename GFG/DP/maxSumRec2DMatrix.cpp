#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int kadane(int *a,int n,int *start,int *end)
{
	int sum=0;
	int flag=0,max=INT_MIN,max_id;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0) flag++;
		if(a[i]>max) 
		{
			max=a[i];
			max_id=i;
		} 
	}
	if(flag==n)
	{
		*start=max_id;
		*end=max_id;
		return max;
	}
	max=INT_MIN;
	*start=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum<0)
		{
			sum=0;
			*start=i+1;
		}
		if(sum>max)
		{
			max=sum;
			*end=i;
		}
	}
	return max;
}
int matrixSum(int **m,int r,int c)
{
	int temp[r];
	int start,end;
	int ans=0;
	int max=INT_MIN,max_col_st,max_col_end,max_row_st,max_row_end;
	for(int i=0;i<c;i++)
	{
		for(int x=0;x<r;x++) temp[x]=0;
		for(int j=i;j<c;j++)
		{
			for(int k=0;k<r;k++) temp[k]+=m[k][j];
            ans=kadane(temp,r,&start,&end);
            if(ans>max)
            {
            	max=ans;
            	max_col_st=i;
            	max_col_end=j;
            	max_row_st=start;
            	max_row_end=end;
            }
		}
	}
	for(int i=max_row_st;i<=max_row_end;i++)
		{
			for(int j=max_col_st;j<=max_col_end;j++)
				cout<<m[i][j]<<" ";
			cout<<endl;
		}

	return max;
}
int main()
{
	int r,c;
	cin>>r>>c;
	int **m=(int**)malloc(r*sizeof(int*));
	for(int i=0;i<r;i++)
		m[i]=(int*)malloc(c*sizeof(int));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) 
			cin>>m[i][j];
    int ans=matrixSum(m,r,c);
    cout<<ans<<endl;
    return 0;
}