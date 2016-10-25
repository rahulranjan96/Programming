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
void levelorder(node *root)
{
	if(root!=NULL)
{
	queue<node*> q;
	node *temp;
	q.push(root);
	int count=0;
	while(!q.empty())
	{
	  count=q.size();
	  while(count--)
	  {
      temp=q.front();
      q.pop();
      cout<<temp->key<<" ";
      if(temp->left!=NULL)
      q.push(temp->left);
      if(temp->right!=NULL)
      q.push(temp->right);
      }
      cout<<endl;
    }
    //cout<<endl;
}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
	stack<node*> st;
	node *temp=NULL;
	st.push(root);
	root=root->left;
	while(!st.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
			st.push(root);
			root=root->left;
		}
   temp=st.top();
   st.pop();
   cout<<temp->key<<" ";
   root=temp->right;
   }
   }
}

void preorder(node *root)
{
	if(root!=NULL)
	{
	stack<node*> st;
	node *temp=NULL;
	st.push(root);
	cout<<root->key<<" ";
	root=root->left;
	while(!st.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
			cout<<root->key<<" ";
			st.push(root);
			root=root->left;
		}
		temp=st.top();
		st.pop();
		root=temp->right;
	}
    }
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
void inorder(node *root)
{
	if(root==NULL) return;
	stack<node*> st;
	node *temp;
	while(root!=NULL)
	{
		st.push(root);
		root=root->left;
		while(root!=NULL)
		{
		  st.push(root);	
		}
		temp=st.top();
		st.pop();
		


	}
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:BFS(Level Order)\n3:DFS(Inorder)\n4:DFS(Preorder)\n5:DFS(Postorder)\n6:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:levelorder(root);
        	       break;
        	case 3:inorder(root);
        	       cout<<endl;
        	       break;
        	case 4:preorder(root);
        	       cout<<endl;
        	       break;
        	case 5:postorder(root);
        	       cout<<endl;
        	       break;
        	case 6:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}

