#include <iostream>
using namespace std;

int *mem;

int fib(int n)
{
  if(mem[n]!=-1)
  	return mem[n];
  else{
   mem[n]=fib(n-1)+fib(n-2);
   return mem[n];
    }
}

int main()
{
	int n;
	cin>>n;
	mem=new int[n+1];
	for(int i=0;i<=n;i++)
		mem[i]=-1;
	mem[0]=1;
	mem[1]=1;
	int ans=fib(n);
	cout<<ans<<endl;
	delete(mem);
	return 0;
}