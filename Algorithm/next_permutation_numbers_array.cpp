

    /**
     * @input A : Integer array
     * @input n1 : Integer array's ( A ) length
     * 
     * @Output Void. Just modifies the args passed by reference 
     */
    void swap(int *a,int *b)
    {
    	int temp=*a;
    	*a=*b;
    	*b=temp;
    }
    void nextPermutation(int* a, int n1) {
        int d=n1;
        int count=0;
        int i,j;
        for(i=0;i<d-1;i++)
        {
        	if(a[i]>=a[i+1])
        		count++;
        }
        if(count==d-1) 
        {
            for(i=0;i<d/2;i++)
            swap(&a[i],&a[d-i-1]);
            return;
        }
       for(i=d-1;i>=1;i--)
       {
         if(a[i-1]<a[i]) break;
       }
       int index1=i-1;
       int max=a[index1];
       int min=INT_MAX;
       int index2=0;
       for(i=index1+1;i<d;i++)
       {
         if(a[i]<min&&a[i]>max)
          {
          min=a[i];
          index2=i;
          }
       }
       swap(&a[index1],&a[index2]);
       for(i=index1+1;i<d;i++)
       for(j=index1+1;j<d-1;j++)
       {
       	if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
       } 
    }

