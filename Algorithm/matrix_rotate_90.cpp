#include <iostream>
#include <cstdio>
using namespace std;

void matrix_rotate_90(int a[][4],int n)
{
	int r=n;
	int c=n;
	int k=0;
	int l=0;
	int i=0;
    int j=0;
	int pre=0;
	int cur=0;
	int rot=n;
	int freq=rot-1;
	while(k<r&&l<c)
	{
        while(freq--){
        	pre=a[k+1][l];
		for(i=l;i<c;i++)
		{
			cur=a[k][i];
			a[k][i]=pre;
			pre=cur;
    	}
    	k++;
    	for(i=k;i<r;i++)
    	{
    		cur=a[i][c-1];
    		a[i][c-1]=pre;
    		pre=cur;
    	}
    	c--;
    	if(k<r)
         {
         	for(i=c-1;i>=l;i--)
         {
         	cur=a[r-1][i];
         	a[r-1][i]=pre;
         	pre=cur;
         }
           r--;
         }
        if(l<c)
         for(i=r-1;i>=k;i--)
         {
         	cur=a[i][l];
         	a[i][l]=pre;
         	pre=cur;
         }
         k--;
         c++;
         r++;
     }
     k++;
     l++;
     c--;
     r--;
     rot-=2;
     freq=rot-1;


	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
        cout<<endl;
	}
}
void matrix_rotate_90_effi(int a[][4],int n)
{
    int x=0,y=0,temp=0;
    int i,j;
    for(x=0;x<n/2;x++)
    {
        for(y=x;y<n-x-1;y++)
        {
            temp=a[x][y];
            a[x][y]=a[n-y-1][x];
            a[n-y-1][x]=a[n-x-1][n-y-1];
            a[n-x-1][n-y-1]=a[y][n-x-1];
            a[y][n-x-1]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        cout<<endl;
    }
}
int main()
{
	int a[][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	matrix_rotate_90_effi(a,4);
}