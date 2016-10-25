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
int isIdentical(node *root1,node *root2)
{
	if(root1!=NULL&&root2!=NULL)
	{
		if(root1->key!=root2->key)
			return 0;
		else return (isIdentical(root1->left,root2->left)&isIdentical(root1->right,root2->right));
	}
	else if(root1==NULL&&root2==NULL)
		return 1;
	else return 0;
}
int main()
{
	int c,key,c1;
	node *root1=NULL;
	node *root2=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Check Identical\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter tree number:";
        	       cin>>c1;
        	       switch(c1)
        	       {
        	       	case 1:cout<<"Enter key to be inserted:";
        	               cin>>key;
        	               root1=insert(root1,key);
        	               break;
        	        case 2:cout<<"Enter key to be inserted:";
        	               cin>>key;
        	               root2=insert(root2,key);
        	               break;
        	        default:cout<<"Please enter valid tree number.\n";
        	       }
        	       break;
        	case 2:if(isIdentical(root1,root2))
        	         cout<<"Identical\n";
        	       else cout<<"Not Identical\n";
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}