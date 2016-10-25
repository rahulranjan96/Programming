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
    else return 0;
}
void printArray(int *path,int length)
{
  for(int i=0;i<length;i++)
  	cout<<path[i]<<" ";
  cout<<endl;
}
void printpath(node *root,int *path,int length)
{
   if(root!=NULL)
   {
   	path[length]=root->key;
   	length++;
   if(root->left==NULL&&root->right==NULL)
    printArray(path,length);
   else
   	{
   	printpath(root->left,path,length);
    printpath(root->right,path,length);
    }
   } 
}
void print(node *root)
{
	int path[height(root)];
	printpath(root,path,0);
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:print(root);
        	       break;;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}