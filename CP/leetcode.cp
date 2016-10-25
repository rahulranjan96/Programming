/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
#include<stdlib.h>


int majorityElement(int* nums, int numsSize) {
    int n=numsSize;
    int i=0,j=0,freq=1;
    for(i=0;i<n;i++)
      printf("%d\n",nums[i]);
    for(i=0;i<n-1;i++)
{   freq=1;
    if(nums[i]!=-1)
     for(j=i+1;j<n;j++)
     {
         if(nums[j]==nums[i])
         {
             nums[j]=-1;
             freq++;
         }
     }
     if(freq>n/2)
      return nums[i];
}
return 0;
}

int main()
{
  int a[]={1};
  printf("%d\n",majorityElement(a,1));

}