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
void leftView(node *root)
{
  if(root==NULL) return;
  queue<node*> q;
  q.push(root);
  int size=0;
  node *temp;
  int flag=0;
  while(!q.empty())
  {
    size=q.size();
    while(size--)
    {
    temp=q.front();
    q.pop();
    if(flag==0)
    {
    	cout<<temp->key<<" ";
    	flag=1;
    }
    if(temp->left!=NULL)
    	q.push(temp->left);
    if(temp->right!=NULL)
    	q.push(temp->right);
    }
    flag=0;
  }
}
int main()
{
	node *root=NULL;
	int c,key;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Left View\n4:Exit\nEnter Choice:";
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
			case 3:leftView(root);
			       cout<<endl;
			       break;
			case 4:return 0;
			default:cout<<"Please enter a valid choice.\n";
			        break;
		}
	}
	return 0;
}