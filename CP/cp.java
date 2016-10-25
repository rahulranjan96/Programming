import java.util.*;
import java.lang.*;
import java.io.*;

/*class cp {
	public static void main (String[] args) {
		//code
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0)
		{
			int a,b;
			a=sc.nextInt();
			b=sc.nextInt();
			a--;
			b--;
			int ans=nCr(a+b,a);
			System.out.println(ans);
			t=t-1;
		}
	}
	public static int nCr(int n,int r)
	{
       if(r==0||r==n||n==1) return 1;
       if(r==1) return n;
       return nCr(n-1,r-1)+nCr(n-1,r);
	}
}*/
class cp
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0)
		{
		int n=sc.nextInt();
		int[] a=new int[n];
		int count=0;
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		for(int i=0;i<n-2;i++)
			for(int j=i+1;j<n-1;j++)
				for(int k=j+1;k<n;k++)
				{
					if(i+j>k||i+k>j||j+k>i)
						count++;
				}
	    System.out.println(count);
		t=t-1;
	    }
	}
}