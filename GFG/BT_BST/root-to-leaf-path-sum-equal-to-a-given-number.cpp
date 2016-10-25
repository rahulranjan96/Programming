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
//Method-1
/*bool pathrecur(node *root,int num,int sum,bool cond)
{
	if(root!=NULL)
	{
		sum+=root->key;
		if(sum==num&&root->left==NULL&&root->right==NULL)
			return true;
		else
		{
			cond=cond||pathrecur(root->left,num,sum,cond);
			if(cond==true)
			return cond;
			cond=cond||pathrecur(root->right,num,sum,cond);
			return cond;
		}
	}
}
bool pathsum(node *root,int num)
{
	if(root==NULL)
		{   
			if(num==0) return true;
			else return false;
		}
    int sum=0;
    bool cond=false;
    return pathrecur(root,num,sum,cond);
}*/
 //Method-2:
/*bool cond;
void pathsum(node *root,int num)
{
	if(root==NULL)
	{
		if(num==0)
		cond=true;
		return;
	}
	else
	{
		num=num-root->key;
		if(num==0&&root->left==NULL&&root->right==NULL)
		{
			cond=true;
			return;
		}
		else
		{
			if(root->left!=NULL)
			pathsum(root->left,num);
		    if(root->right!=NULL)
			pathsum(root->right,num);
		}
	}
}*/
//Method-3
bool pathsum(node *root,int num)
{
  if(root==NULL)
  {
  	if(num==0) return true;
  	else return false;
  }
  bool cond=false;
  num=num-root->key;
  if(root->left==NULL&&root->right==NULL&&num==0)
  	return true;
  else
  {
  	if(root->left)
  	cond=cond|pathsum(root->left,num);
    if(cond==true)
  	return cond;
    if(root->right)
    cond=cond|pathsum(root->right,num);
    return cond;
  }
}
int main()
{
	int c,key,num=0;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Path Sum\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<"Enter path sum:";
        	       cin>>num;
        	       /*if(pathsum(root,num))
        	       	cout<<"YES\n";
        	       else cout<<"NO\n";*/
        	       /*cond=false;
        	       pathsum(root,num);
        	       if(cond==true)
        	       	cout<<"YES\n";
        	       else cout<<"NO\n";*/
        	       if(pathsum(root,num))
        	       	cout<<"YES\n";
        	       else cout<<"NO\n";
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}