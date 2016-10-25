#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
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
		root=new node[1];
		root->left=NULL;
		root->right=NULL;
		root->key=key;
		return root;
	}
	else if(key>=root->key)
	{
		root->right=insert(root->right,key);
		return root;
	}
	else
	{
		root->left=insert(root->left,key);
		return root;
	}
}
node *search(node *root,int key)
{
	if(root->key==key)
		return root;
	else if(key>=root->key)
		return search(root->right,key);
	else return search(root->left,key);
}
node* min(node *root)
{
	if(root->left!=NULL)
		return min(root->left);
	else return root;
}
node* parent(node *root,node *temp)
{
  if(root)
 {
  if(root->left==temp||root->right==temp)
  	return root;
  else
  {
   return parent(root->left,temp);
   return parent(root->right,temp);
  }
 }
}
node* del(node *root,int key)
{
	node *temp=search(root,key);
	if(temp->left==NULL&&temp->right==NULL)
	{
	  if(temp==root)
	  	{
	  		free(temp);
            return NULL;
        }
      node *p=parent(root,temp);
      if(p->left==temp)
      {
      	free(p->left);
      	p->left=NULL;
      }
      else
      {
      	free(p->right);
      	p->right=NULL;
      }
	}
	else if(temp->left==NULL||temp->right==NULL)
	{
		if(temp->left==NULL)
		{
			node *del=temp->right;
			temp->key=temp->right->key;
			temp->left=temp->right->left;
			temp->right=temp->right->right;
			free(del);
		}
		else
		{
			node *del=temp->left;
			temp->key=temp->left->key;
			temp->right=temp->left->right;
			temp->left=temp->left->left;
			free(del);
		}
	}
	else
	{
		node *succ=min(temp->right);
		temp->key=succ->key;
		node *p=parent(root,succ);
		if(p->left==succ)
		{
			free(p->left);
			p->left=NULL;
		}
		else
		{
			free(p->right);
			p->right=NULL;
		}
	}
	return root;
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
int main()
{
	node *root=NULL;
	int key,c;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Delete\n4:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter key to be inserted:";
			       cin>>key;
			       root=insert(root,key);
			       break;
			case 2:inorder(root);
			       cout<<endl;
			       break;
			case 3:cout<<"Enter key to be deleted:";
			       cin>>key;
			       root=del(root,key);
			       break;
			case 4:return 0;
			default:cout<<"Enter valid choice\n";
		}
	}
}