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
node *lca(node *root,int k1,int k2)
{
	if(root==NULL)
		return NULL;
	if(root->key==k1||root->key==k2)
		return root;
	node *left_lca=lca(root->left,k1,k2);
	node *right_lca=lca(root->right,k1,k2);
	if(left_lca!=NULL&&right_lca!=NULL)
		return root;
	else if(left_lca)
		return left_lca;
	else return right_lca;
}
int height(node *root,int key,int dist)
{
	if(root!=NULL)
	{
	if(root->key==key) return dist;
    int l=height(root->left,key,dist+1);
    if(l!=-1) return l;
	int r=height(root->right,key,dist+1);
	return r;
    }
    return -1;
}
int distance(node *root,int k1,int k2)
{
	node *temp=lca(root,k1,k2);
	int d1=height(temp,k1,0);
	int d2=height(temp,k2,0);
	return d1+d2;
}
int main()
{
	node *root=NULL;
	int c,key;
	int k1,k2;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Find Distance\n4:Exit\nEnter Choice:";
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
			case 3:cout<<"Enter key values between which distance is to be found:";
			       cin>>k1>>k2;
			       cout<<distance(root,k1,k2);
			       cout<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}