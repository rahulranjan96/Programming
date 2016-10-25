#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
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
int maxWidth(node *root)
{
	if(root==NULL)
		return 0;
	queue<node*> q;
	int max=INT_MIN;
	int count=0;
	node *temp=0;
	q.push(root);
	while(!q.empty())
	{
        count=q.size();
        if(count>max)
        	max=count;
        while(count--)
        {
          temp=q.front();
          q.pop();
          if(temp->left!=NULL)
          	q.push(temp->left);
          if(temp->right!=NULL)
          	q.push(temp->right);
        }
	}
	return max;
}
int main()
{
	int c,key;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Maximum Width\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<maxWidth(root)<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}