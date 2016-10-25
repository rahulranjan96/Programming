/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 *
 * typedef struct Interval interval;
 */
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
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
    int largest;
    if(lt<=n&&a[lt].start>a[i].start)
    largest=lt;
    else largest=i;
    if(rt<=n&&a[rt].start>a[largest].start)
    largest=rt;
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        maxheapify(a,n,largest);
    }
}
void maxheap(interval *a,int n)
{
    int i=0;
    for(i=n/2;i>=0;i--)
    maxheapify(a,n,i);
}
void heapsort(interval *a,int n)
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
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a<=b) return a;
    else return b;
}
interval* merge(interval *intervals, int sz, int *len) {
    heapsort(intervals,sz-1);
    interval *stack=(interval*)malloc(sz*sizeof(interval));
    int i=0,j=0;
    stack[0]=intervals[0];
    j=1;
    for(i=1;i<sz;i++)
    {
        stack[j]=intervals[i];
        while(j>0&&stack[j-1].end>=stack[j].start)
        {
            stack[j-1].start=min(stack[j-1].start,stack[j].start);
            stack[j-1].end=max(stack[j-1].end,stack[j].end);
            j--;
        }
        j++;
    }
    *len=j;
    return stack;
}
