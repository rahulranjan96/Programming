#include <iostream>
using namespace std;
void k_pascal_row(int k)
{
 int *pre=new int[k];
 int *cur=new int[k];
 int n=0;
 pre[0]=1;
 n++;
 int i=0;
 while(n<k)
 {
 	n++;
 	i=0;
 	cur[i]=1;
 	i++;
 	while(i<n)
 	{
 		cur[i]=pre[i]+pre[i-1];
 		i++;
 	}
 	for(i=0;i<k;i++)
 		pre[i]=cur[i];

 }
 for(i=0;i<k;i++)
 	cout<<pre[i]<<" ";

}
int main()
{
	int k=0;
	cin>>k;
	k_pascal_row(k);
	cout<<endl;
}