#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}node;

int max(int,int);
node* left_rotate(node*);
node* right_rotate(node*);
int balance_factor(node*);
int height(node*);
node* insert(node*);
int max(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}
node* left_rotate(node *root)
{
	node *x=root->right;
	node *y=x->left;
	root->right=y;
	x->left=root;
	return x;
}
node* right_rotate(node *root)
{
	node *x=root->left;
	node *y=x->right;
	root->left=y;
	x->right=root;
	return x;
}
int balance_factor(node *root)
{
	int hl=height(root->left);
	int hr=height(root->right);
	return hl-hr;
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
	int bf1=balance_factor(root);
	if(bf1<-1)
	{  
		if(key<root->right->key)
	    root->right=right_rotate(root->right);
		root=left_rotate(root);
	}
	else if(bf1>1)
	{  
		if(key>root->left->key)
		root->left=left_rotate(root->left);
        root=right_rotate(root);
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
int height(node *root)
{
	if(root!=NULL)
		return 1+max(height(root->left),height(root->right));
	else return -1;
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Height\n4:Exit\nEnter Choice:";
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
			case 3:cout<<height(root)<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
		}
	}
	return 0;
}