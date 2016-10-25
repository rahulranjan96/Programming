#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */
/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */
/*void longestPalindrome(char* A) {
   int n=strlen(A);
   int mem[n][n];
   int i,j,k;
   int max=INT_MIN,start_id=0;
   for(i=0;i<n;i++)
   {
       mem[i][i]=1;
       if(1>max)
       {
           max=1;
           start_id=i;
       }
   }
   for(i=0;i<n-1;i++)
   {
       if(A[i]==A[i+1])
       {
           mem[i][i+1]=1;
           if(2>max)
           {
               max=2;
               start_id=i;
           }
       }
       else mem[i][i+1]=0;
   }
   for(k=2;k<n;k++)
   for(i=0;i<n-k;i++)
   {
      j=i+k;
       if(mem[i+1][j-1])
       {
           if(A[i]==A[j])
           {
               mem[i][j]=1;
               if(j-i+1>max)
               {
                   max=j-i+1;
                   start_id=i;
               }
           }
           else mem[i][j]=0;
       }
       else mem[i][j]=0;
   }
   char *s=(char*)malloc((max+1)*sizeof(char));
   s[max]='\0';
   for(i=0;i<max;i++)
     s[i]=A[start_id++];
   printf("%s\n",s);
}


int main()
{
    char s[10000];
    scanf("%s",s);
    longestPalindrome(s);
    return 0;
}*/
  
/*typedef struct Node1{
    int key;
  }node1;
typedef struct Node{
  node1 *b;
  int c;
}node;
int main()
{
  node *a=(node*)malloc(sizeof(node));
  (*a).b=(node1*)malloc(sizeof(node1));
  (*(*a).b).key=1;
  (*a).c=2;
  printf("%d %d\n",(*(*a).b).key,(*a).c);
  return 0;
}*/

/* 
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int *a,int low,int high)
{
  int i=low-1;
  int j=low;
  int temp=a[high];
  for(j=low;j<high;j++)
  {
    if(a[j]<=temp)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[high]);
  return i+1;
}
int rand_partition(int *a,int low,int high)
{
  time_t t;
  srand((unsigned)time(&t));
  int n=(high-low+1);
  int r=rand()%n+low;
  swap(&a[r],&a[high]);
  return partition(a,low,high);
}

void quick_sort(int *a,int low,int high)
{
  if(low<high)
  {
    int p=rand_partition(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
  }
}
void insertion_sort(int *a,int n)
{
  int i,j,temp;
  for(int i=1;i<n;i++)
  {
    temp=a[i];
    j=i-1;
    while(j>=0&&a[j]>temp)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
}
void merge(int *a,int l,int m,int h)
{
  int n1=m-l+1;
  int n2=h-m;
  int *lt=(int*)malloc((n1+1)*sizeof(int));
  int *rt=(int*)malloc((n2+1)*sizeof(int));
  int i=0,j=0,k=0;
  for(i=0;i<n1;i++)
    lt[i]=a[l+i];
  for(i=0;i<n2;i++)
    rt[i]=a[m+1+i];
  lt[n1]=INT_MAX;
  rt[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=l;k<=h;k++)
  {
    if(lt[i]<=rt[j])
    {
      a[k]=lt[i];
      i++;
    }
    else
    {
      a[k]=rt[j];
      j++;
    }
  }
}
void merge_sort(int *a,int low,int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}
*/
/*
void merge_inversions(int *a,int l,int m,int h,unsigned long long int *inv)
{
  int n1=m-l+1;
  int n2=h-m;
  int *lt=(int*)malloc((n1+1)*sizeof(int));
  int *rt=(int*)malloc((n2+1)*sizeof(int));
  int i=0,j=0,k=0;
  for(i=0;i<n1;i++)
    lt[i]=a[l+i];
  for(i=0;i<n2;i++)
    rt[i]=a[m+1+i];
  lt[n1]=INT_MAX;
  rt[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=l;k<=h;k++)
  {
    if(lt[i]<=rt[j])
    {
      a[k]=lt[i];
      i++;
    }
    else
    {
      *inv=*inv+n1-i;
      a[k]=rt[j];
      j++;
    }
  }
}

void merge_sort_inversions(int *a,int low,int high,unsigned long long int *inv)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    merge_sort_inversions(a,low,mid,inv);
    merge_sort_inversions(a,mid+1,high,inv);
    merge_inversions(a,low,mid,high,inv);
  }
}

void counting_sort(int *a,int n)
{
  int i=0;
  int max=a[0];
  for(i=1;i<n;i++)
    if(a[i]>max) max=a[i];
  int *c=(int*)malloc((max+1)*sizeof(int));
  for(i=0;i<n;i++)
    c[a[i]]++;
  for(i=1;i<=max;i++)
    c[i]+=c[i-1];
  int *b=(int*)malloc(n*sizeof(int));
  for(i=n-1;i>=0;i--)
    {
      b[c[a[i]]-1]=a[i];
      c[a[i]]--;
    }
  for(i=0;i<n;i++)
    a[i]=b[i];
}
int main()
{
  int n=0,i=0;
  scanf("%d",&n);
  int *a=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  unsigned long long int inv=0;
  merge_sort_inversions(a,0,n-1,&inv);
  printf("%llu",inv);
  printf("\n");
  return 0;
}*/



void merge_inversions(int *a,int l,int m,int h,unsigned long long int *inv)
{
  int n1=m-l+1;
  int n2=h-m;
  int *lt=(int*)malloc((n1+1)*sizeof(int));
  int *rt=(int*)malloc((n2+1)*sizeof(int));
  int i=0,j=0,k=0;
  for(i=0;i<n1;i++)
    lt[i]=a[l+i];
  for(i=0;i<n2;i++)
    rt[i]=a[m+1+i];
  lt[n1]=INT_MAX;
  rt[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=l;k<=h;k++)
  {
    if(lt[i]<=rt[j])
    {
      a[k]=lt[i];
      i++;
    }
    else
    {
      *inv=*inv+n1-i;
      a[k]=rt[j];
      j++;
    }
  }
}

void merge_sort_inversions(int *a,int low,int high,unsigned long long int *inv)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    merge_sort_inversions(a,low,mid,inv);
    merge_sort_inversions(a,mid+1,high,inv);
    merge_inversions(a,low,mid,high,inv);
  }
}
void merge(int *a,int l,int m,int h)
{
  int n1=m-l+1;
  int n2=h-m;
  int *lt=(int*)malloc((n1+1)*sizeof(int));
  int *rt=(int*)malloc((n2+1)*sizeof(int));
  int i=0,j=0,k=0;
  for(i=0;i<n1;i++)
    lt[i]=a[l+i];
  for(i=0;i<n2;i++)
    rt[i]=a[m+1+i];
  lt[n1]=INT_MAX;
  rt[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=l;k<=h;k++)
  {
    if(lt[i]<=rt[j])
    {
      a[k]=lt[i];
      i++;
    }
    else
    {
      a[k]=rt[j];
      j++;
    }
  }
}
void merge_sort(int *a,int low,int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}
int main()
{
  int n=0;
  scanf("%d",&n);
  int *a=(int*)malloc((n+1)*sizeof(int));
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  int start=1,end=1,j;
  for(int i=n;i>1;i--)
  {
    if(a[i-1]>a[i])
    {
      start=i;
      j=i-1;
      while(i<=n)
      {
        if(a[i]==a[start]) i++;
        else break;
      }
      start=i-1;
      while(j>1&&a[j-1]>=a[j])
      {
        j--;
      }
      end=j;
      break;
    }
  }
  unsigned long long int inv=0;
  merge_sort(a,end,start);
  merge_sort_inversions(a,1,n,&inv);
  if(inv>0) printf("no\n");
  else printf("yes\n%d %d\n",end,start);
  return 0;
}