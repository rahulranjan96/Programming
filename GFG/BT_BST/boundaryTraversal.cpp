#include <iostream>
#include <queue>
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
void leftTraversal(node *root)   //AnticlockWise
{
  if(root->left!=NULL)
  	{
  	if(!(root->left->left==NULL&&root->left->right==NULL))
  		{
  			cout<<root->left->key<<" ";
  			leftTraversal(root->left);
  		}
  	}
  else if(root->right!=NULL)
  {
  	if(!(root->right->left==NULL&&root->right->right==NULL))
  	{
  		cout<<root->right->key<<" ";
  		leftTraversal(root->right);
  	}
  }
}
void rightTraversal(node *root)  //AnticlockWise
{
   if(root->right!=NULL)
   {
   	if(!(root->right->left==NULL&&root->right->right==NULL))
   	{
   		rightTraversal(root->right);
        cout<<root->right->key<<" ";
   	}
   }
   else if(root->left!=NULL)
   {
   	if(!(root->left->left==NULL&&root->left->right==NULL))
   	{
   		rightTraversal(root->left);
   		cout<<root->left->key<<" ";
   	}
   }
}
void leafTraversal(node *root)   //AnticlockWise
{
  	if(root->left==NULL&&root->right==NULL)
  		cout<<root->key<<" ";
  	else
  	{  
  		if(root->left) leafTraversal(root->left);
  		if(root->right) leafTraversal(root->right);
  	}
}
void boundaryTraversal(node *root)
{
  if(root!=NULL)
 {
  if(root->left==NULL&&root->right==NULL)
  	cout<<root->key<<" ";
  else
  {
  cout<<root->key<<" ";
  leftTraversal(root);
  leafTraversal(root);
  rightTraversal(root);
  }
  
 }
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Boundary Traversal\n4:Exit\nEnter Choice:";
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
			case 3:boundaryTraversal(root);
			       cout<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}