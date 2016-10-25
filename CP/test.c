#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int **a=(int**)malloc(10*sizeof(int*));
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		a[i]=(int*)malloc(10*sizeof(int));
		printf("%lu\n",sizeof(a[i]));
	}
}