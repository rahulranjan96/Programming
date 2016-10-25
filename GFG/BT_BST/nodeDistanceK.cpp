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
void nodeAtK(node *root,int k)
{ 
if(root!=NULL)
 {
  if(k==0)
 	{
 		cout<<root->key<<" ";
 		return;
 	}
  	nodeAtK(root->left,k-1);
  	nodeAtK(root->right,k-1);
  }
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Node at K\n4:Exit\nEnter Choice:";
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
			case 3:cout<<"Enter the value of K:";
			       cin>>key;
			       nodeAtK(root,key);
			       cout<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}