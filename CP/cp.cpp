#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

/*
int max(int a,int b)
{
  if(a>=b) return a;
  else return b;
}
int **mem;
int knapsack(int *v,int *w,int W,int n)
{
  if(mem[n][W]!=-1) return mem[n][W];
  if(W<=0) return 0;
  if(n==0) return 0;
  if(w[n-1]>W)
  {
   mem[n][W] = knapsack(v,w,W,n-1);
   return mem[n][W];
  }
{
  mem[n][W]=max(v[n-1]+knapsack(v,w,W-w[n-1],n-1),knapsack(v,w,W,n-1));
  return mem[n][W];
}
}
void printItems(int *v,int *w,int W,int n)
{
	if(W<=0) return;
	if(n<=0) return;
	if(w[n-1]>W) printItems(v,w,W,n-1);
	else 
	{
	  if((v[n-1]+mem[n-1][W-w[n-1]])>mem[n-1][W])
		{
			cout<<v[n-1]<<" ";
			printItems(v,w,W-w[n-1],n-1);
		}
	  else printItems(v,w,W,n-1);
	}
}
int main()
{
  int n,W;
  cin>>n>>W;
  int *v=new int[n];
  int *w=new int[n];
  for(int i=0;i<n;i++)
    cin>>v[i];
  for(int i=0;i<n;i++)
    cin>>w[i];
  mem=new int*[n+1];
  for(int i=0;i<=n;i++)
    mem[i]=new int[W+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=W;j++)
      mem[i][j]=-1;
  int ans=knapsack(v,w,W,n);
  cout<<ans<<endl;
  printItems(v,w,W,n);
  cout<<endl;
  return 0;
}
*/
/*int main()
{
  int n=0;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int *lis=new int[n];
  lis[0]=1;
  for(int i=1;i<n;i++)
  {
    lis[i]=1;
    for(int j=0;j<i;j++)
    {
      if(a[i]>a[j]&&lis[j]+1>lis[i])
        lis[i]=lis[j]+1;
    }
  }
  int max=lis[0];
  for(int i=1;i<n;i++)
  {
    if(lis[i]>max)
      max=lis[i];
  }
  cout<<max<<endl;
  for(int i=n-1;i>=0;i--)
  {
    if(lis[i]==max)
      {
        cout<<a[i]<<" ";
        max--;
      }
  }
  return 0;
}*/

/*int **mem;
int lcs(char *s1,int n,char *s2,int m)
{
  if(mem[n][m]!=-1) return mem[n][m];
  if(n==0||m==0) return 0;
  if(s1[n-1]==s2[m-1]) 
  {
    mem[n][m]=1+lcs(s1,n-1,s2,m-1);
    return mem[n][m];
  }
  mem[n][m] = max(lcs(s1,n-1,s2,m),lcs(s1,n,s2,m-1));
  return mem[n][m];
}
void printSubsequence(char *s1,int n,char *s2,int m)
{
  if(n==0||m==0) return;
  if(s1[n-1]==s2[m-1])
    {
      cout<<s1[n-1];
      printSubsequence(s1,n-1,s2,m-1);
    }
  else if(mem[n-1][m]>mem[n][m-1])
    printSubsequence(s1,n-1,s2,m);
  else printSubsequence(s1,n,s2,m-1);
}
int main()
{
  char s1[1000000];
  char s2[1000000];
  scanf("%[^\n]%*c",s1);
  scanf("%[^\n]%*c",s2);
  int n=strlen(s1);
  int m=strlen(s2);
  mem=new int*[n+1];
  for(int i=0;i<=n;i++)
    mem[i]=new int[m+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
      mem[i][j]=-1;
  int ans=lcs(s1,n,s2,m);
  cout<<ans<<endl;
  printSubsequence(s1,n,s2,m);
  cout<<endl;
  return 0;
}*/
/*
int **mem;
int min3(int a,int b,int c)
{
  if(a<=b&&a<=c) return a;
  if(b<=a&&b<=c) return b;
  if(c<=a&&c<=b) return c;
}
int editDistance(char *s1,int n,char *s2,int m)  //Insert,Remove,Replace
{
  if(mem[n][m]!=-1) return mem[n][m];
  if(n==0) return m;
  if(m==0) return n;
  if(s1[n-1]==s2[m-1])
  { 
    mem[n][m] = editDistance(s1,n-1,s2,m-1);
    return mem[n][m];
  }
  mem[n][m] = 1+min3(editDistance(s1,n,s2,m-1),
                editDistance(s1,n-1,s2,m),
                editDistance(s1,n-1,s2,m-1));
  return mem[n][m];
}
int main()
{
  char s1[1000000];
  char s2[1000000];
  scanf("%[^\n]%*c",s1);
  scanf("%[^\n]%*c",s2);
  int n=strlen(s1);
  int m=strlen(s2);
  mem =new int*[n+1];
  for(int i=0;i<=n;i++)
    mem[i]=new int[m+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
      mem[i][j]=-1;
  int ans=editDistance(s1,n,s2,m);
  cout<<ans<<endl;
  return 0;
}*/
/*
int min3(int a,int b,int c)
{
  if(a<=b&&a<=c) return a;
  if(b<=a&&b<=c) return b;
  if(c<=a&&c<=b) return c;
}
int **mem;
int minCost(int **a,int n,int m)
{
  if(mem[n][m]!=-1) return mem[n][m];
  if(n<0||m<0) return INT_MAX;
  if(n==0&&m==0){
    mem[n][m] = a[n][m];
    return mem[n][m];
  }
  if(n==0){ mem[n][m]=a[n][m]+minCost(a,n,m-1);
            return mem[n][m];
          }
  if(m==0){ mem[n][m]=a[n][m]+minCost(a,n-1,m);
            return mem[n][m];
          }
  mem[n][m]=a[n][m]+min3(minCost(a,n-1,m),
                         minCost(a,n-1,m-1),
                         minCost(a,n,m-1));
  return mem[n][m];
}
void printPath(int **a,int n,int m)
{
  if(n<0||m<0) return;
  cout<<'-'<<'>'<<'('<<n<<","<<m<<')';
  if(n==0&&m==0) return;
  else if(m==0) printPath(a,n-1,m);
  else if(n==0) printPath(a,n,m-1);
  else if(mem[n-1][m]<=mem[n-1][m-1]&&mem[n-1][m]<=mem[n][m-1])
    printPath(a,n-1,m);
  else if(mem[n-1][m-1]<=mem[n-1][m]&&mem[n-1][m-1]<=mem[n][m-1])
    printPath(a,n-1,m-1);
  else printPath(a,n,m-1);

}
int main()
{
  int m,n;
  cin>>n>>m;
  int **a=new int*[n];
  for(int i=0;i<n;i++)
    a[i]=new int[m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];
  mem = new int*[n];
  for (int i=0;i<n;i++)
   mem[i]=new int[m];
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
    mem[i][j]=-1;
  int ans=minCost(a,n-1,m-1);
  cout<<ans<<endl;
  printPath(a,n-1,m-1);
  cout<<endl;
  for(int i=0;i<n;i++)
    delete(mem[i]);
  delete(mem);
  return 0;
}
*/
/*
int **mem;
int coinChange(int *a,int n,int sum)
{
  if(sum==0) return 1;
  if(sum<0) return 0;
  if(sum>0&&n<=0) return 0;
  if(mem[n-1][sum]!=-1) return mem[n-1][sum];
  mem[n-1][sum]=coinChange(a,n-1,sum)+coinChange(a,n,sum-a[n-1]);
  return mem[n-1][sum];
}
int main()
{
  int n=0,sum=0;
  cin>>n>>sum;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  mem=new int*[n];
  for(int i=0;i<n;i++)
    mem[i]=new int[sum+1];
  for(int i=0;i<n;i++)
    for(int j=0;j<=sum;j++)
      mem[i][j]=-1;
  int ans=coinChange(a,n,sum);
  cout<<ans<<endl;
  return 0;
}*/
/*
int max(int a,int b)
{
  if(a>=b) return a;
  else return b;
}
int **mem;
int lps(char *s,int l,int r)
{
  if(mem[l][r]!=-1) return mem[l][r];
  if(l>r) return 0;
  if(l==r) return 1;
  if(s[l]==s[r])
  {
    mem[l][r]=2+lps(s,l+1,r-1);
    return mem[l][r];
  }
  if(s[l]!=s[r])
  {
    mem[l][r]=max(lps(s,l,r-1),lps(s,l+1,r));
    return mem[l][r];
  }
}
void printPalindrome(char *s,int l,int r,char *pal,int i,int j)
{
  if(l>r) return;
  if(l==r) pal[i]=s[l];
  if(s[l]==s[r]) {
    pal[i]=s[l];
    pal[j]=s[r];
    printPalindrome(s,l+1,r-1,pal,i+1,j-1);
  }
  else
  {
    if(mem[l][r-1]>=mem[l+1][r])
      printPalindrome(s,l,r-1,pal,i,j);
    else printPalindrome(s,l+1,r,pal,i,j);
  }
}
int main()
{
  char s[1000000];
  scanf("%[^\n]%*c",s);
  int n=strlen(s);
  mem=new int*[n];
  for(int i=0;i<n;i++)
    mem[i]=new int[n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      mem[i][j]=-1;
  int ans=lps(s,0,n-1);
  cout<<ans<<endl;
  char pal[ans+1];
  pal[ans]='\0';
  printPalindrome(s,0,n-1,pal,0,ans-1);
  cout<<pal;
  cout<<endl;
  return 0;
}
*/
/*
int *mem;
int rodCut(int *p,int n)
{
  if(mem[n]!=-1) return mem[n];
  if(n<=0) return 0;
  int max=INT_MIN;
  int temp=0;
  for(int i=1;i<=n;i++)
  {
    temp=p[i]+rodCut(p,n-i);
    if(temp>max)
      max=temp;
  }
  mem[n]=max;
  return mem[n];
}
void printlength(int *p,int n)
{
  if(n<=0) return;
  int max=INT_MIN,temp,length;
  for(int i=1;i<=n;i++)
  {
     temp=p[i]+mem[n-i];
     if(temp>max)
     {
      max=temp;
      length=i;
     }
  }
  cout<<length<<" ";
  printlength(p,n-length);
}
int main()
{
  int n;
  cin>>n;
  int *p=new int[n+1];
  for(int i=1;i<=n;i++)
    cin>>p[i];
  mem=new int[n+1];
  for(int i=1;i<=n;i++)
    mem[i]=-1;
  mem[0]=0;
  int ans=rodCut(p,n);
  cout<<ans<<endl;
  for(int i=0;i<=n;i++)
    cout<<mem[i]<<" ";
  cout<<endl;
  printlength(p,n);
  cout<<endl;
  return 0;
}
*/
/*
int main()
{
  int n=0;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int *lis=new int[n];
  lis[0]=a[0];
  for(int i=1;i<n;i++)
  {
    lis[i]=a[i];
    for(int j=0;j<i;j++)
    {
      if(a[i]>a[j]&&lis[j]+a[i]>lis[i])
        lis[i]=lis[j]+a[i];
    }
  }
  int max=lis[0];
  for(int i=1;i<n;i++)
  {
    if(lis[i]>max)
      max=lis[i];
  }
  cout<<max<<endl;
  for(int i=n-1;i>=0;i--)
  {
    if(lis[i]==max)
    {
      cout<<a[i]<<" ";
      max-=a[i];
    }
  }
  cout<<endl;
  return 0;
}
*/
/*
int main()
{
  int n=0;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int max=INT_MIN;
  int sum=0;
  int start=0,end=0;
  for(int i=0;i<n;i++)
  {
    sum+=a[i];
    if(sum<0)
      {
      	start=i+1;
      	sum=0;
      }
    if(sum>max)
      {
      	end=i;
      	max=sum;
      }
  }
  cout<<max<<endl;
  cout<<start<<" "<<end<<endl;
  for(int i=start;i<=end;i++)
  	cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}*/
/*
int **mem;
int ssp(int *s,int n,int sum)
{
	if(sum==0) return 1;
	if(sum<0) return 0;
	if(n<=0) return 0;
	if(mem[n][sum]!=-1) return mem[n][sum];
	if(s[n-1]>sum)
	{ 
		mem[n][sum]=ssp(s,n-1,sum);
		return mem[n][sum];
	}
	mem[n][sum]=ssp(s,n-1,sum)||ssp(s,n-1,sum-s[n-1]);
	return mem[n][sum]; 
}
int main()
{
	int n=0,sum=0;
	cin>>sum>>n;
	int *s=new int[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	mem=new int*[n+1];
	for(int i=0;i<=n;i++)
		mem[i]=new int[sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++)
			mem[i][j]=-1;
	int ans=ssp(s,n,sum);
	cout<<ans<<endl;
	return 0;
}
*/
/*
void prevSmaller(vector<int> &A) {
    stack<int> st;
    int n=A.size();
    st.push(n-1);
    map<int,int> mp;
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty()&&A[i]<A[st.top()])
        {
            cout<<A[st.top()]<<"--"<<A[i]<<endl;
            mp[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mp[st.top()]=-1;
        st.pop();
    }
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(mp[i]!=-1)
        ans.push_back(A[mp[i]]);
        else ans.push_back(-1);
    }
    for(int i=0;i<n;i++)
      cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
  int n=0;
  cin>>n;
  vector<int> v;
  int key;
  while(n--)
  {
   cin>>key;
   v.push_back(key);
  }
  prevSmaller(v);
  return 0;
}
*//*
typedef struct Node{
  int key;
  struct Node *left;
  struct Node *right;
  int hd;
}node;
int max(int a,int b)
{
  return (a>b)?a:b;
}
node *insert(node *root,int key)
{
  if(root==NULL)
  {
    root=new node[1];
    root->key=key;
    root->left=NULL;
    root->right=NULL;
    return root;
  }
  else if(key>root->key)
    root->right=insert(root->right,key);
  else root->left=insert(root->left,key);
  return root;
}
int height(node *root)
{
  if(root) return 1+max(height(root->left),height(root->right));
  else return -1;
}
int balancefactor(node *root)
{
  if(!root) return 0;
  int hl=height(root->left);
  int hr=height(root->right);
  return hl-hr;
}
node *rightrotate(node *root)
{ 
  node *x=root->left;
  node *y=x->right;
  root->left=y;
  x->right=root;
  return x;
}
node *leftrotate(node *root)
{
  node *x=root->right;
  node *y=x->left;
  root->right=y;
  x->left=root;
  return x;
} 
node *insertbbst(node *root,int key)
{
  if(root==NULL)
  {
    root=new node[1];
    root->key=key;
    root->left=NULL;
    root->right=NULL;
  }
  else if(key>=root->key)
    root->right=insertbbst(root->right,key);
  else root->left=insertbbst(root->left,key);
  int bf=balancefactor(root);
  if(bf<-1||bf>1)
  {
    if(bf>1)
    {
      if(key>root->left->key)
        root->left=leftrotate(root->left);
      root=rightrotate(root);
    }
    else if(bf<-1)
    {
      if(key<root->right->key)
        root->right=rightrotate(root->right);
      root=leftrotate(root);
    }
  }
  return root;
}
*//*
int getDiff(node *root)
{
  if(!root) return 0;
  int sum_even=0;
  int sum_odd=0;
  node *temp=NULL;
  int count=0;
  queue<node*> q;
  q.push(root);
  int flag=0;
  while(!q.empty())
  {
    count=q.size();
    while(count--)
    {
      temp=q.front();
      q.pop();
      if(!flag)
        sum_even+=temp->key;
      else sum_odd+=temp->key;
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
    flag=!flag;
  }
  return sum_even-sum_odd;
}*/
/*
int func(node *root,int level)
{
  if(root==NULL) return 0;
  if(root->left==NULL&&root->right==NULL&&(level%2)) return level;
  level++;
  return max(func(root->left,level),func(root->right,level)); 
}
int dol(node *root)
{
  int level=1;
  return func(root,level);
}*/
/*
int utilityFunc(node *root,int &res)
{
  if(root==NULL) return 0;
  int l=utilityFunc(root->left,res);
  int r=utilityFunc(root->right,res);
  int single_max=max(max(l,r)+root->key,root->key);
  int top_max=max(single_max,l+r+root->key);
  res=max(res,top_max);
  return single_max;
}
int maxSum(node *root)
{
  int res=0;
  utilityFunc(root,res);
  return res;
}
*//*
void topView(node *root)
{
  if(!root) return;
  map<int,int> mp;
  queue<node*> q;
  root->hd=0;
  q.push(root);
  int size=0;
  node *temp=NULL;
  int hd=0;
  while(!q.empty())
  {
      temp=q.front();
      hd=temp->hd;
      q.pop();
      if(mp.find(hd)==mp.end())
      {
          mp[hd]=temp->key;
          cout<<temp->key<<" ";
      }
      if(temp->left)
      {
        temp->left->hd=hd-1;
        q.push(temp->left);
      }
      if(temp->right)
      {
        temp->right->hd=hd+1;
        q.push(temp->right);
      }
  }
  cout<<endl;
}
void bottomView(node *root)
{
  map<int,int> mp;
  queue<node*> q;
  int hd=0;
  node *temp=NULL;
  root->hd=0;
  q.push(root);
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    hd=temp->hd;
    mp[hd]=temp->key;
    if(temp->left)
    {
      temp->left->hd=hd-1;
      q.push(temp->left);
    }
    if(temp->right)
    {
      temp->right->hd=hd+1;
      q.push(temp->right);
    }
  }
  map<int,int>::iterator itr;
  for(itr=mp.begin();itr!=mp.end();itr++)
  {
    cout<<itr->second<<" ";
  }
  cout<<endl;
}
*//*
int KsmallestEle(node *root,int k)
{
  if(root)
  {

  }
}
int main()
{
  node *root=NULL;
  int key,c,ans,k;
  while(1)
  {
    cout<<"1:Insert\n2:k-th Smallest Element\n4:Exit\nEnter Choice:";
    cin>>c;
    switch(c)
    {
      case 1:cout<<"Enter key to be inserted:";
             cin>>key;
             root=insert(root,key);
             break;
      case 2:cout<<"Enter the value of K:";
             cin>>k;
             int ans = KsmallestEle(root,k);
             cout<<ans<<endl;
             break;
      case 4:return 0;
      default:cout<<"Please enter a valid choice.\n";
    }
  }
  return 0;
}
*//*Given In-Order and Pre-Order
int searchid(int *ino,int st,int end,int val)
{
  for(int i=st;i<=end;i++)
    if(ino[i]==val) return i;
}
node* buildTree(int *pre,int *ino,int st,int end,node *root)
{
  if(st>end) return NULL;
  static int preId=0;
  root=insert(root,pre[preId++]);
  if(st==end) return root;
  int inId=searchid(ino,st,end,root->key);
  root->left=buildTree(pre,ino,st,inId-1,root->left);
  root->right=buildTree(pre,ino,inId+1,end,root->right);
  return root;
}*//* //Given In-Order and Post-Order
int searchid(int *ino,int st,int end,int key)
{
  for(int i=st;i<=end;i++)
  {
    if(ino[i]==key) return i;
  }
}
node* buildTree(int *post,int post_st,int post_end,int *ino,int ino_st,int ino_end,node *root)
{
  if(ino_st>ino_end) return NULL;
  root=insert(root,post[post_end]);
  if(ino_st==ino_end) return root;
  int id=searchid(ino,ino_st,ino_end,root->key);
  int num=id-ino_st;
  root->left=buildTree(post,post_st,post_st+num-1,ino,ino_st,id-1,root->left);
  root->right=buildTree(post,post_st+num,post_end-1,ino,id+1,ino_end,root->right);
  return root;

}*//*
int searchid(int *ino,int ino_st,int ino_end,int key)
{
  for(int i=ino_st;i<=ino_end;i++)
  {
    if(ino[i]==key) return i;
  }
}
node *buildTree(int *level,int level_st,int level_end,int *ino,int ino_st,int ino_end,node *root)
{
  if(ino_st>ino_end) return NULL;
  root=insert(root,level[level_st]);
  int id=searchid(ino,ino_st,ino_end,root->key);
  int *left=new int[id-ino_st];
  int *right=new int[ino_end-id];
  int k=0;
  for(int i=level_st+1;i<=level_end;i++)
    for(int j=ino_st;j<id;j++)
    {
      if(ino[j]==level[i]) left[k++]=level[i];
    }
    k=0;
  for(int i=level_st+1;i<=level_end;i++)
    for(int j=id+1;j<=ino_end;j++)
    {
      if(ino[j]==level[i]) right[k++]=level[i];
    }
  root->left=buildTree(left,0,id-ino_st-1,ino,ino_st,id-1,root->left);
  root->right=buildTree(right,0,ino_end-id-1,ino,id+1,ino_end,root->right);
  return root;
}*//*
void inorder(node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
  }
}
void preorder(node *root)
{
  if(root)
  {
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(node *root)
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
  }
}
void levelOrder(node *root)
{
  if(!root) return;
  node *temp;
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    cout<<temp->key<<" ";
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }
}
int main()
{
  int n;
  cout<<"Enter number of nodes in the Tree:";
  cin>>n;
  int *pto=new int[n];
  int *ino=new int[n];
  cout<<"Enter the values of Post-Order-Order Traversal:\n";
  for(int i=0;i<n;i++)
    cin>>pto[i];
  cout<<"Enter the values of In-Order Traversal:\n";
  for(int i=0;i<n;i++)
    cin>>ino[i];
  node *root=NULL;
  root=buildTree(pto,0,n-1,ino,0,n-1,root);
  cout<<"PreOrder:";preorder(root);cout<<endl;
  cout<<"InOrder:";inorder(root);cout<<endl;
  cout<<"PostOrder:";postorder(root);cout<<endl;
  cout<<"LevelOrder:";levelOrder(root);cout<<endl;
  return 0;
}*//*
node *constructBST(int *a,int low,int high,node *root)
{
  if(low>high) return NULL;
  int mid=(low+high)/2;
  root = insertbbst(root,a[mid]);
  if(low==high) return root;
  root->left=constructBST(a,low,mid-1,root->left);
  root->right=constructBST(a,mid+1,high,root->right);
  return root;
}

int main()
{
  int n=0;
  cout<<"Enter the size of the array:";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter the elements of the array:\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  node *root=NULL;
  root=constructBST(a,0,n-1,root);
  cout<<"Preorder:";preorder(root);cout<<endl;
  cout<<"Inorder:";inorder(root);cout<<endl;
  cout<<"Postorder:";postorder(root);cout<<endl;
}*//*     //AGGRCOWS
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int *a,int p,int r)
{
  int i=p-1;
  int j=p;
  int x=a[r];
  for(j=p;j<r;j++)
  {
    if(a[j]<=x)
     {
      i++;
      swap(&a[i],&a[j]);
     }
  }
  swap(&a[i+1],&a[r]);
  return i+1;
}
int random_partition(int *a,int p,int r)
{
  int n=(r-p+1);
  time_t t;
  srand((unsigned)time(&t));
  int i=rand()%n+p;
  swap(&a[i],&a[r]);
  return partition(a,p,r);
}
void quick_sort(int *a,int p,int r)
{
  if(p<r)
  {
    int part=random_partition(a,p,r);
    quick_sort(a,p,part-1);
    quick_sort(a,part+1,r);
  }
}
int func(int *a,int n,int c,int dist)
{
  int count=0;
  int pre=a[0];
  for(int i=1;i<n;i++)
  {
    if((a[i]-pre)>=dist)
    {
      count++;
      pre=a[i];
    }
  }
  if(count>=c) return 1;
  else return 0;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,c;
    cin>>n>>c;            
    int *a=new int[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    quick_sort(a,0,n-1);
    int low=0,mid=0;
    int high=a[n-1];
    int result=0;
    while(low<=high)
     {
        mid=(low+high)/2;
        if(func(a,n,c-1,mid)==1)
        {
          result=mid;
          low=mid+1;
        }
        else if(func(a,n,c-1,mid)==0)
        {
          high=mid-1;
        }
     }
   cout<<result<<endl;
  }
  return 0;
}*//*
int main()
{
  int t=0;
  cin>>t;
  while(t--)
  {
    int n,sum;
    cin>>n>>sum;
    int *a=new int[n];  
    for(int i=0;i<n;i++)
      cin>>a[i];
    int sum_cur=a[0];
    int start=0;
    int flag=0;
    for(int i=1;i<n;i++)    //15, 2, 4, 8, 9, 5, 10, 23::::::::23
    {
      cout<<sum_cur<<endl;
      if(sum_cur>sum)
      while(start<=i&&sum_cur>sum)
        {
          sum_cur-=a[start];
          start++;
        }
      if(sum_cur==sum)
       {
        cout<<"Found between "<<start<<" and "<<i-1<<endl;
        flag=1;
        break;
       }
      if(sum_cur<sum)
       sum_cur+=a[i]; 
    }
    if(!flag)
    {
      while((start<=n-1)&&sum_cur>sum)
      {
        sum_cur-=a[start];
        start++;
      }
      if(sum_cur==sum)
        cout<<"Found between "<<start<<" and "<<n<<endl;
    }
  }
  return 0;
}*//*
int add(int a,int b)
{
  if(!b) return a;
  else return add(a^b,(a&b)<<1);
}
int sub(int a,int b)
{
  if(!b) return a;
  else return sub(a^b,(~a&b)<<1);
}
int gcd(int a,int b)
{
  if(b>a) return gcd(b,a);
  else if(b==0) return a;
  else return gcd(b,a%b);
}
int main()
{
  int a,b,c;
  while(1)
  {
    cout<<"1:Add\n2:Subtract\n3:GCD\n4:Exit\nEnter Choice:";
    cin>>c;
    switch(c)
    {
      case 1:cout<<"Enter values of \"a\" and \"b\":";
             cin>>a>>b;
             cout<<add(a,b)<<endl;
             break;
      case 2:cout<<"Enter values of \"a\" and \"b\":";
             cin>>a>>b;
             cout<<sub(a,b)<<endl;
             break;
      case 3:cout<<"Enter values of \"a\" and \"b\":";
             cin>>a>>b;
             cout<<gcd(a,b)<<endl;
             break;
      case 4:return 0;
      default:cout<<"Please enter a valid choice\n";
              break;
    }
  }
  return 0;
}*//*
void permute(vector<int> &a,int l, int r,vector<vector<int> > &v)
{
  if(l==r)
  {
    v.push_back(a);
  }
  else
  {
    int temp;
    for(int i=l;i<=r;i++)
    {
        temp=a[i];
        a[i]=a[l];
        a[l]=temp;
        permute(a,l+1,r,v);
        temp=a[i];
        a[i]=a[l];
        a[l]=temp;
    }
  }
}
int main()
{
  vector<int> a;
  vector<vector<int> > v;
  int key;
  for(int i=0;i<3;i++)
  {
    cin>>key;
    a.push_back(key);
  }
  permute(a,0,2,v);
  for(int i=0;i<v.size();i++){
    for(int j=0;j<a.size();j++)
    {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}*//*
int search(int *ino,int l,int h,int key)
{
  for(int i=l;i<=h;i++)
    if(ino[i]==key) return i;
}
void generatePostorder(int *in,int *pre,int *post,int l,int h)
{
  if(l>h) return;
  static int pre_id=l;
  static int post_id=l;
  int id=search(in,l,h,pre[pre_id++]);
  if(l<id) generatePostorder(in,pre,post,l,id-1);
  if(id<h) generatePostorder(in,pre,post,id+1,h);
  post[post_id++]=in[id];
}
int main()
{
  int n=0;
  cout<<"Enter number of node in tree:";
  cin>>n;
  int *pre=new int[n];
  int *post=new int[n];
  int *in=new int[n];
  cout<<"Enter PreOrder Traversal:";
  for(int i=0;i<n;i++)
    cin>>pre[i];
  cout<<"Enter Inorder Traversal:";
  for(int i=0;i<n;i++)
    cin>>in[i];
  generatePostorder(in,pre,post,0,n-1);
  cout<<"PostOrder Traversal:";
  for(int i=0;i<n;i++)
    cout<<post[i]<<" ";
  cout<<endl;
  return 0;
}*//*
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int max_diff,min_elmt;
  min_elmt=a[0];
  max_diff=a[1]-a[0];
  for(int i=1;i<n;i++)
  {
    if(a[i]-min_elmt>max_diff)
      max_diff=a[i]-min_elmt;
    if(a[i]<min_elmt) min_elmt=a[i];
  }
  cout<<max_diff;
  cout<<endl;
}*//*
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int i=0;
  while(i<n-1)
  {
      while((i<n-1)&&(a[i+1]<=a[i])) i++;
      cout<<i<<" "; i++;
      while((i<n)&&(a[i]>=a[i-1])) i++;
      cout<<(i-1)<<endl;
  }
  return 0;
}*//*
#define max(a,b) ((a)>=(b)?a:b)
int main()
{
  int n;
  cin>>n;
  int *price=new int[n];
  int *profit=new int[n];
  for(int i=0;i<n;i++) cin>>price[i];
  int max_price=price[n-1];
  for(int i=n-2;i>=0;i--)
  {
    if(price[i]>max_price) max_price=price[i];
    profit[i]=max(profit[i+1],max_price-price[i]);
  }
  int min_price=price[0];
  for(int i=1;i<n;i++)
  {
    if(price[i]<min_price) min_price=price[i];
    profit[i]=max(profit[i-1],profit[i]+price[i]-min_price);
  }
  cout<<profit[n-1]<<endl;
  return 0;
}*//*
#define min(a,b) ((a)<=(b)?a:b)
#define max(a,b) ((a)>=(b)?a:b)

int main()
{
  int n=0;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int max_here=1;
  int min_here=1;
  int max_product=INT_MIN;
  int temp;
  for(int i=0;i<n;i++)
  {
    if(a[i]>0)
    {
      max_here=max_here*a[i];
      min_here=min(min_here*a[i],1);       
    }
    else if(a[i]==0)
    {
      max_here=1;
      min_here=1;
    }
    else
    {
      temp=max_here;
      max_here=max(min_here*a[i],1);
      min_here=temp*a[i];
    }
    if(max_here>max_product) max_product=max_here;
  }
  cout<<max_product<<endl;
  return 0;
}*//*
#define abs(x) ((x)<0?(-1*x):x)
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
  {
    if(a[abs(a[i])]>0) a[abs(a[i])]=-1*a[abs(a[i])];
    else cout<<abs(a[i])<<" ";
  }
  cout<<endl;
  return 0;
}*//*
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)
int median(int *lt,int *rt,int n)
{
  int low_lt=0,high_lt=n-1,low_rt=0,high_rt=n-1;
  int mid_lt,mid_rt;
  while((high_lt-low_lt+1)>2&&(high_rt-low_rt+1)>2)
  {
     mid_lt=(low_lt+high_lt)/2;
     mid_rt=(low_rt+high_rt)/2;
     if(lt[mid_lt]==rt[mid_rt]) return lt[mid_lt];
     else if(lt[mid_lt]>rt[mid_rt])
     {
       high_lt=mid_lt;
       low_rt=mid_rt;
     }
     else
     {
      low_lt=mid_lt;
      high_rt=mid_rt;
     }
  }
 return (max(lt[low_lt],rt[low_rt])+min(lt[high_lt],rt[high_rt]))/2;

}
int main()
{
  int n;
  cin>>n;
  int *lt=new int[n];
  int *rt=new int[n];
  for(int i=0;i<n;i++) cin>>lt[i];
  for(int i=0;i<n;i++) cin>>rt[i];
  int ans=median(lt,rt,n);
  cout<<ans<<endl;
  return 0;
}*//*
int main()
{
  char s[1000];
  scanf("%[^\n]%*c",s);
  int *visited=new int[256];
  for(int i=0;i<256;i++)
    visited[i]=-1;
  int pre_id=0;
  visited[s[0]]=0;
  int cur_len=0,max_len=INT_MIN;
  for(int i=1;i<strlen(s);i++)
  {
    pre_id=visited[s[i]];
    if(pre_id==-1||(i-pre_id)>cur_len)
      cur_len++;
    else
    {
      if(cur_len>max_len)
        max_len=cur_len;
      cur_len=i-pre_id;
    }
    visited[s[i]]=i;
  }
  if(cur_len>max_len) max_len=cur_len;
  cout<<max_len<<endl;
  return 0;
}*//*
int foo(int n)
{
  if(n==0||n==1) return 1;
  else return n*foo(n-1);
}
int main()
{
  char s[100];
  scanf("%[^\n]%*c",s);
  int *count=new int[26];
  int n=strlen(s);
  for(int i=0;i<n;i++)
     count[s[i]-(int)'A']++;
  int *fact=new int[n+1];
  for(int i=0;i<=n;i++)
    fact[i]=foo(i);
  int *aux=new int[n];
  for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
      if(s[j]<s[i]) aux[i]++;
  int rank=0;
  int divisor=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
      
    rank+=aux[i]*fact[n-i-1];
  }
  cout<<rank+1<<endl;
  return 0;
}*//*
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int temp,cur;
  for(int i=0;i<3;i++)
  {
    cur=a[0];
    for(int j=n-1;j>=0;j--)
    {
      temp=a[j];
      a[j]=cur;
      cur=temp;
    }
    for(int j=0;j<n;j++)
      cout<<a[j]<<" ";
    cout<<endl;
  }
  return 0;
}*//*   //Segregate 0s and 1s
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int l=0,r=n-1;
  while(l<r)
  {
    if(a[l]==0) l++;
    if(a[r]==1) r--; 
    if(l<r)
      swap(&a[l],&a[r]);
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}*//*   //Segregate Odd and Even
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int l=0,r=n-1;
  while(l<r)
  {
    while(a[l]%2==0) l++;
    while(a[r]%2!=0) r--;
    if(l<r) swap(&a[l],&a[r]);
  }
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}*//*//Stock Span
int main()
{
   int n;
   cin>>n;
   int *a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   stack<int> st;
   st.push(0);
   int *span=new int[n];
   span[0]=1;
   for(int i=1;i<n;i++)
   {
    while(!st.empty()&&a[i]>=a[st.top()])
      st.pop();
    span[i]=((!st.empty())?i-st.top():i+1);
    st.push(i);
   }
   for(int i=0;i<n;i++) cout<<span[i]<<" ";
   cout<<endl;
   return 0;
}*//*
int main()
{
  int t=0;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int low=0,high=n-1,mid,next,prev,ans;
    while(low<=high)                  
    {     
      cout<<a[low]<<" "<<a[high]<<endl;
      if(a[low]<a[high])
      {
        ans=low;
        break;
      }
      mid=(low+high)/2;
      next=(mid+1)%n;
      prev=(mid-1+n)%n;
      if(a[mid]<a[prev]&&a[mid]<=a[next])
      {
        ans=mid;
        break;
      }
      else if(a[mid]<a[high]) high=mid-1;
      else low=mid+1;
    }
    cout<<ans<<endl;
  }
  return 0;
}*//*
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
void countsort(int *a,int l,int h)
{
  int *count=new int[10];
  for(int i=l;i<=h;i++)
    count[a[i]]++;
  for(int i=1;i<10;i++)
    count[i]+=count[i-1];
  int n=h-l+1;
  int *temp=new int[n];
  for(int i=h;i>=l;i--)
  {
    temp[count[a[i]]-1]=a[i];
    count[a[i]]--;
  }
  for(int i=0;i<n;i++)
    a[i+l]=temp[i];
  delete(temp);
}
int nextPermute(int *a,int n)
{
    int i=0;
    for(i=n-1;i>0;i--)
    {
        if(a[i-1]<a[i])
          break;
    }
    if(i==0) return -1;
    int id=i-1;
    int min=INT_MAX;
    int min_id;
    for(i=id+1;i<n;i++)
    {
        if(a[i]>a[id])
        {
            if(a[i]<min) 
            {
                min=a[i];
                min_id=i;
            }
        }
    }
    swap(&a[min_id],&a[id]);
    if(id+1==n-1) return 1;
    else countsort(a,id+1,n-1);
    return 1;
}
int main() {
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      int m=n;
      int d=0;
      while(m>0)
      {
          m=m/10;
          d++;
      }
      int *a=new int[d];
      for(int i=d-1;i>=0;i--)
      {
          a[i]=n%10;
          n=n/10;
      }
      int cond=nextPermute(a,d);
      if(cond==-1) cout<<cond<<endl;
      else
      {
          int num=0;
          for(int i=0;i<d;i++)
           num=num*10+a[i];
           cout<<num<<endl;
      }
  }
  return 0;
}*//*
int powmod(int x, int n, int d) {
    if(x==0) return 0;
    if(n==0) return 1;
    if(n==1) 
    {
        while(x<0) x=d+x;
        return x%d;
    }
    if(n%2==0)
    {
      long long int temp=powmod(x,n/2,d)%d;
       cout<<temp<<endl;
       return ((temp%d)*(temp%d))%d;
    }
    else
    {
        long long int temp=powmod(x,n/2,d)%d;
        cout<<temp<<endl;
        return ((x%d)*(temp%d)*(temp%d))%d;
    }
}
int main()          
{
  int ans=powmod(71045970,41535484,64735492);
  cout<<ans<<endl;
}*//*
int main()
{
  while(1){
  string s;
  cin>>s;
  int flag=0,i,j;
  int signal=0;
  while(1)
  {
  for(i=0;i<s.length();i++)                     
  {
    for(j=i+1;j<s.length();j++)
    {
      if(s[j]!=s[i])
        break;
      else flag=1;
    }
    if(flag)
    {
      s.erase(i,j-i);
      flag=0;
      signal=1;
      i--;
    }
  }
    if(!signal) break;
    else signal=!signal;
  }
  cout<<s<<endl;
}
  return 0;
}*//*
int main()
{
  string s;
  string ans;
  cin>>s;
  int count=0,i,j;
  for(i=0;i<s.length();i++)
  {
    for(j=i+1;j<s.length();j++)
    {
      if(s[j]==s[i]) count++;
      else break;
    }
    ans.push_back(s[i]);
    ans.push_back((char)(j-i+(int)'0'));
    i=j-1;
  }
  cout<<ans<<endl;
  return 0;
}*//*
int main()
{
  string s;
  string temp;
  int ans=0;
  int signal=0;
  int k;
  cin>>s;
  cin>>k;
  int *count=new int[26];
  for(int i=0;i<s.length();i++)
  { 
    signal=0;
    for(int m=0;m<26;m++) count[m]=0;
    for(int j=i;j<s.length();j++)
    {
      if(count[s[j]-'a']==0) signal++;
      count[s[j]-'a']++;      
      if(signal==k) ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}*//*
int main()
{
  string s;
  getline(cin,s);
  int i=0,j=1;
  while(s[i]==' ')
    i++;
  s.erase(0,i);
  i=0,j=1;
  int flag=0;
  while(j<s.length())
  {
   if(s[j]==' ')
   {
    if(!flag)
    {
      flag=1;
      i++;
      s[i]=s[j];
    }
    j++;
   }
   else
   {
    i++;
    cout<<i<<" "<<j<<endl;
    s[i]=s[j];
    j++;
    flag=0;
   }
   cout<<s<<endl;

  }
  s.erase(i+1);
  cout<<s<<endl;
  return 0;
}*//*
int main()
{
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int i=0,j=1;
  while(j<n)
  {
    if(a[j]==a[i]) j++;
    else {
      i++;
      a[i]=a[j];
      j++;
    }
  }
  for(j=0;j<=i;j++) cout<<a[j]<<" ";
  cout<<endl;
  return 0;
}*//*
int main()
{
  vector<int> v;
  int n=0,key=0;
  cin>>n;
  while(n--) 
    {
      cin>>key;
      v.push_back(key);
    }
  for(int i=0;i<v.size();i++) v[i]=v[i]*v[i];
  sort(v.begin(),v.end());
  int i=0,j=0,k=0;
  n=v.size();
  for(i=n-1;i>=2;i--)
  {
    j=i-1;
    k=0;
    while(k<j)
    {
      if(v[k]+v[j]==v[i])
        {
          cout<<(int)sqrt(v[k])<<" "<<(int)sqrt(v[j])<<" "<<(int)sqrt(v[i])<<endl;
          k++;
          j--;
        }
      else if(v[k]+v[j]>v[i]) j--;
      else if(v[k]+v[j]<v[i]) k++;
    }
  }
 return 0;
}*/
/*
int foo(int *A,int n1,int B,int C)
{
  int temp[n1];
  int sum=0,i=0,j=0,count=0;
  for(i=0;i<n1;i++)
  {
  sum+=A[i];
  temp[i]=sum;
  }
  for(i=0;i<n1;i++)
  for(j=i;j<n1;j++)
  {
    if((temp[j]-temp[i]>=B)&&(temp[j]-temp[i]<=C)) count++;
  }
  return count;
}
*//*
void toh(int n,char from,char to,char aux)
{
  if(n==1)
  {
    cout<<"Disk 1 from:"<<from<<"->"<<to<<endl;
    return;
  }
  toh(n-1,from,aux,to);
  cout<<"Disk "<<n<<" from:"<<from<<"->"<<to<<endl;
  toh(n-1,aux,to,from);
}
int main()
{
  char from='A';
  char aux='B';
  char to='C';
  int n=0;
  cin>>n;
  toh(n,from,to,aux);
  return 0;
}*//*
int main()
{
  string s;
  cin>>s;
  string temp="";
  int sum=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]>='0'&&s[i]<='9') temp+=s[i];
    else
    {
      sum+=atoi(temp.c_str());
      temp="";
    }
  }
  sum+=atoi(temp.c_str());
  cout<<sum<<endl;
  return 0;
}*//*
int main()
{
  string s;
  cin>>s;
  int *count=new int[26];
  for(int i=0;i<s.length();i++)
    count[s[i]-'a']++;
  string beg="",mid="",end="";
 for(char c='a';c<='z';c++)
  {
    if(count[c-'a']%2!=0)
    {
      mid=c;
      count[c-'a']--;
      c--;
    }
    else
    {
      for(int i=0;i<count[c-'a']/2;i++)
        {
          beg.push_back(c);
        }
    }
  }
  end=beg;
  reverse(end.begin(),end.end());
  cout<<beg+mid+end<<endl;
  return 0;
}*//*
int mod(int a,int b)
{
  int r=a%b;
  if(r<0) return r+b;
  else return r;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    cout<<a%b<<" "<<mod(a,b)<<endl;
  }
  return 0;
}*//*
typedef struct Node
{
  int key;
  struct Node *next;
}node;
node* insert(node *head,int key)
{
  node *temp=new node[1];
  temp->key=key;
  temp->next=head;
  return temp;
}
void print(node *head)
{
  while(head)
    {
      cout<<head->key<<" ";
      head=head->next;
    }
  cout<<endl;
}
node* del(node *head,node *temp,node *prev)
{
  if(temp==head)
  {
    head=head->next;
    free(temp);
    return head;
  }
  prev->next=temp->next;
  free(temp);
  return head;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  int a,b;
  cin>>a>>b;
  node *head=NULL;
  for(int i=b;i>=a;i--)
      if(i!=1)
      head=insert(head,i);
  //print(head);
  node *temp=head;
  node *prev=head;
  for(int i=2;i<=sqrt(b);i++)
  {
    temp=head;
    prev=head;
    while(temp)
    {
      if((temp->key)%i==0&&temp->key!=i)
      {
        //cout<<temp->key<<" "<<i<<endl;
        head=del(head,temp,prev);
      }
      prev=temp;
      temp=temp->next;
    }
  }
  print(head);
  }
  return 0;
}*//*
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    if(x==y||x==y+2)
    {
      if(x==y)
      {
        if(x&1) cout<<2*x-1<<endl;
        else cout<<2*x<<endl;
      }
      else
      {
        if(x&1) cout<<x+y-1<<endl;
        else cout<<x+y<<endl;
      }
    }
    else cout<<"No Number"<<endl;
  }
  return 0;
}*//*
int powmod(int a,int b)
{
  if(a==0) return 0;
  if(b==0) return 1;
  if(b&1)
  {
    int temp=powmod(a,b/2)%10;
    return (((temp*temp)%10)*a)%10;
  }
  else 
  {
    int temp=powmod(a,b/2)%10;
    return (temp*temp)%10;
  }
} 
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    cout<<powmod(a,b)<<endl;
  }
  return 0;
}*//*
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++)
      {
        if(i*j<=n) count++; 
        else break;
      }
      cout<<count<<endl;
  return 0;
}*//*
int main()
{
  int a,b,c;
  while(1)
  {
    cin>>a>>b>>c;
    if(a==0&&b==0&&c==0) return 0;
    if((b-a)==(c-b)) cout<<"AP "<<(2*c-b)<<endl;
    else if((b/a)==(c/b)) cout<<"GP "<<((c*c)/b)<<endl;
  }
  return 0;
}*/
int main()
{
  int n;
  while(1)
{
  cin>>n;
  if(n==-1) return 0;
  int *a=new int[n];
  int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%n==0)
  {
    int ans=0;
    sum=sum/n;
    for(int i=0;i<n;i++)
      if(sum>a[i]) ans+=sum-a[i];
    cout<<ans<<endl;
  }
  else cout<<"-1"<<endl;
}
  return 0;
}


