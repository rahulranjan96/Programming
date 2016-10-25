int* repeatedNumber(const int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
         *length_of_array = 2; // length of result array
          int *result=(int*)malloc(2*sizeof(int));
         long long int xor1,x=0,y=0;
         int i=0;
         xor1=A[0];
         for(i=1;i<n1;i++)
         xor1=xor1^A[i];
         for(i=1;i<=n1;i++)
         xor1=xor1^i;
         long long int set=xor1 & ~(xor1-1);
         for(i=0;i<n1;i++)
         {
             if(A[i]&set) x=x^A[i];
             else y=y^A[i];
         }
         for(i=1;i<=n1;i++)
         {
             if(i&set) x=x^i;
             else y=y^i;
         }
         for(i=0;i<n1;i++)
         {
             if(A[i]==x||A[i]==y)
             break;
         }
         if(A[i]==x)
         {
             result[0]=x;
             result[1]=y;
         }
         else
         {
             result[0]=y;
             result[1]=x;
         }
         return result;
}