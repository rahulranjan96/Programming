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
int sumTree(node *root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return 1;
	else 
	{
		int cond=sumTree(root->left)&&sumTree(root->right);
		if(!cond) return 0;
		int l=0,r=0;
		if(root->left!=NULL)
		 if(root->left->left==NULL&&root->left->right==NULL)
		  l=root->left->key;
		 else l=2*root->left->key;
		if(root->right!=NULL)
		 if(root->right->left==NULL&&root->right->right==NULL)
		  r=root->right->key;
		 else r=2*root->right->key;
		if(root->key==(l+r))
			return 1;
		else return 0;
	}
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Check Sum Tree\n4:Exit\nEnter Choice:";
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
			case 3:if(sumTree(root))
			       cout<<"Yes"<<endl;
			       else cout<<"No"<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}