#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
  struct Interval {
      int start;
      int end;
  };
 
  typedef struct Interval interval;
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
 void swap(interval *a,interval *b)
 {
     interval temp=*a;
     *a=*b;
     *b=temp;
 }
 void maxheapify(interval *a,int n,int i)
 {
     int lt=2*i+1;
     int rt=2*i+2;
     int largest=0;
     if(lt<=n&&a[lt].start>a[i].start)
     largest=lt;
     else largest=i;
     if(rt<=n&&a[rt].start>a[largest].start)
     largest=rt;
     if(largest!=i)
     {
         swap(&a[i],&a[largest]);
         maxheapify(a,n,largest);
     }
 }
 void maxheap(interval *a,int n)
 {
     int i=0;
     for(i=n/2;i>=0;i--)
     maxheapify(a,n,i);
 }
 void heap_sort(interval *a,int n)
 {
     int i=0;
     maxheap(a,n);
     for(i=n;i>0;i--)
     {
         swap(&a[i],&a[0]);
         n--;
         maxheapify(a,n,0);
     }
 }
int min(int a,int b)
{
    if(a<=b)
     return a;
    else return b;
}
int max(int a,int b)
{
    if(a>=b) 
    return a;
    else return b;
}
interval* insert(interval *intervals, int sz, interval newInterval, int *len) {
    interval *a=(interval*)malloc((sz+1)*sizeof(interval));
    int i=0;
    a[0]=newInterval;
    if(a[0].start>a[0].end)
    {
    	int temp=a[0].start;
    	a[0].start=a[0].end;
    	a[0].end=temp;
    }
    for(i=1;i<=sz;i++)
    a[i]=intervals[i-1];
    heap_sort(a,sz);
    printf("%d\n\n",sz);
    //for(i=0;i<=sz;i++) printf("%d %d\n",a[i].start,a[i].end);
    interval *stack=(interval*)malloc((sz+1)*sizeof(interval));
    int j=1;
    stack[0]=a[0];
    for(i=1;i<=sz;i++)
    { 
        stack[j]=a[i];
     while(j>0&&stack[j-1].end>=stack[j].start)
     {
      stack[j-1].start=min(stack[j-1].start,stack[j].start);
      stack[j-1].end=max(stack[j-1].end,stack[j].end);
      j--;
     }
     j++;
    }
    *len=j;
    
    for(i=0;i<*len;i++)
    	printf("%d %d\n",stack[i].start,stack[i].end);
    return stack;
    
    
}

int main()
{
	interval a[29]= {{1,3}, {0,1}, {4,6}, {1,6}, {2,8}, {5,6}, {2,4}, {0,9}, {1,2}, {3,8}, {1,6}, {5,6}, {7,9}, {4,8}, {4,4}, {2,3}, {3,3}, {1,9}, {1,7}, {9,9}, {7,9}, {2,4}, {2,7}, {5,5}, {1,6}, {4,8}, {0, 8}, {4,9}, {8, 9}};
	interval b;
	b.start=3;
	b.end=9;

	int x;
	insert(a,29,b,&x);
}