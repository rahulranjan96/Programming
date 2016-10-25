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
node* min(node *root)
{
	if(root->left==NULL)
		return root;
	else return min(root->left);
}
node* search(node *root,int key)
{
	if(root==NULL)
		return root;
	else if(root->key==key)
		return root;
	else if(key>root->key)
		return search(root->right);
	else return search(root->left);
}
node *successor(node *root,int key)
{
	node *keyNode=search(root,key);
	if(keyNode==NULL)
	{
		cout<<"Error.. Key Not Present\n";
		return keyNode;
	}
	else if(keyNode->right!=NULL)
		return min(keyNode->right);
	node *p=keyNode->parent;
	while(p!=NULL&&keyNode==p->right)
	{
		keyNode=p;
		p=keyNode->parent;
	}
	return p;
}
node *successor(node *root,int key)
{
	node *keyNode=search(root,key);
	if(keyNode==NULL)
	{
		cout<<"Error..Key Not Present\n";
		return;
	}
	else if(keyNode->right!=NULL)
		return min(key->right);
	node *succ=NULL;
	while(root!=keyNode)
	{
		if(key>root->key)
			root=root->right;
		else
		{
			succ=root;
			root=root->left;
		}
	}
	return succ;
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Successor\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<"Enter the key whose successor is to be found:";
        	       cin>>key;
        	       node *temp=successor(root,key);
        	       if(temp!=NULL)
        	       	cout<<temp->key<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}