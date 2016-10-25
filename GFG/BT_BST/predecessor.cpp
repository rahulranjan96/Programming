#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
}node;

node* insert(node *root,int key)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->key=key;
		root->left=NULL;
		root->right=NULL;
	}
	else if(key>=root->key)
		root->right=insert(root->right,key);
	else if(key<root->key)
		root->left=insert(root->left,key);
	return root;
}
node* max(node *root)
{
	if(root->right==NULL)
		return root;
	else return max(root->right);
}
node* search(node *root,int key)
{
	if(root==NULL)
		return root;
	else if(root->key==key)
		return root;
	else if(key>root->key)
		return search(root->right,key);
	else return search(root->left,key);
}
node* predecessor(node *root,int key)
{
   node *keyNode=search(root,key);
   if(keyNode==NULL)
   {
   	cout<<"Error..Key Not Present\n";
   	return keyNode;
   }
   if(keyNode->left!=NULL)
   	return max(keyNode->left);
   node *p=keyNode->parent;
   while(p!=NULL&&p->left==keyNode)
   {
   	keyNode=p;
   	p=keyNode->parent;
   }
   return p;
}
node* predecessor(node *root,int key)
{
	node *keyNode=search(root,key);
	if(keyNode==NULL)
	{
		cout<<"Error..Key Not Present\n";
		return keyNode;
	}
	if(keyNode->left!=NULL)
		return max(keyNode->left);
	node *pred=NULL;
	while(root!=keyNode)
	{
		if(key>root->key)
		{
          pred=root;
          root=root->right;
		}
		else 
			root=root->left;
	}
	return pred;
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Predecessor\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<"Enter key whose predecessor is to be found:";
        	       cin>>key;
        	       node *temp=predecessor(root,key);
        	       if(temp!=NULL)
        	       	cout<<temp->key<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}