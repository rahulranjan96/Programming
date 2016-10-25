#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <utility>
#include <vector>
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
int height(node *root)
{
	if(root!=NULL)
		return 1+max(height(root->left),height(root->right));
	else return -1;
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
void auxfunc(node *root,int hd,map< int,vector<int> > &m)
{
	if(root==NULL) return;
	m[hd].push_back(root->key);
	auxfunc(root->left,hd-1,m);
	auxfunc(root->right,hd+1,m);
}
void verticalPrint(node *root)
{
  map< int,vector<int> > m;
  auxfunc(root,0,m);
  map< int,vector<int> >::iterator itr;
  for(itr=m.begin();itr!=m.end();itr++)
  	{
  	 for(int j=0;j<itr->second.size();j++)
         cout<<itr->second[j]<<" ";
    	 cout<<endl;
     }
}

int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Height\n4:Vertical Print\n5:Exit\nEnter Choice:";
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
			case 4:verticalPrint(root);
			       break;
            case 5:return 0;
			default:cout<<"Please enter a valid choice.\n";
		}
	}
	return 0;
}