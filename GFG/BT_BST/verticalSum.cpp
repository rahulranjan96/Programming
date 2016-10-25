#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}node;

int max(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}
node* insert(node *root,int key)
{
	if(root==NULL)
	{
		root=new node[1];
		root->key=key;
		root->left=NULL;
		root->right=NULL;
	}
	else if(key>=root->key)
	{
		root->right=insert(root->right,key);
	}
	else
	{
		root->left=insert(root->left,key);
	}
  return root;
}
int inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
void minLeft(node *root,int *l)
{
	*l=*l-1;
	if(root->left!=NULL)
		minLeft(root->left,l);
}
void maxRight(node *root,int *r)
{
	*r=*r+1;
	if(root->right!=NULL)
		maxRight(root->right,r);
}
void helperfunc(node *root,int *sum_array,int k,int HD)
{ 
  sum_array[HD+k]+=root->key;
  if(root->left!=NULL)
  helperfunc(root->left,sum_array,k,HD-1);
  if(root->right!=NULL)
  helperfunc(root->right,sum_array,k,HD+1);
}
void verticalSum(node *root)
{
  int l=0,r=0;
  if(root->left!=NULL)
  	minLeft(root->left,&l);
  if(root->right!=NULL)
  	maxRight(root->right,&r);
  int n=r-l+1;
  int k=-1*l;
  int *sum_array=new int[n];
  sum_array[k]+=root->key;
  if(root->left!=NULL)
  helperfunc(root->left,sum_array,k,-1);
  if(root->right!=NULL)
  helperfunc(root->right,sum_array,k,1);
  for(int i=0;i<n;i++)
  	cout<<sum_array[i]<<" ";
  cout<<endl;
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Vertical Sum\n4:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter the key to be inserted:";
			       cin>>key;
			       root=insert(root,key);
			       break;
			case 2:inorder(root);
			       cout<<endl;
			       break;
			case 3:verticalSum(root);
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}