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
void printAncestors(node *root,int key)
{
	if(root->key==key)
		cout<<root->key<<" ";
	else 
	{
		if(key>root->key)
		{

			cout<<root->key<<" ";
			printAncestors(root->right,key);
		}
		else 
		{
			cout<<root->key<<" ";
			printAncestors(root->left,key);
		}
	}
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Print Ancestors\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<"Enter key whose ancestors are to be printed:";
        	       cin>>key;
        	       printAncestors(root,key);
        	       cout<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}