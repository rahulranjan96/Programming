#include <iostream>
#include <cstdlib>
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
int childrenSumCheck(node *root)
{
  if(root==NULL||(root->left==NULL&&root->right==NULL))
  	return 1;
  if(root->left!=NULL&&root->right==NULL)
    {
    	if(root->left->key==root->key)
    		return childrenSumCheck(root->left);
    	else return 0;
    }
   if(root->right!=NULL&&root->left==NULL)
   {
   	if(root->right->key==root->key)
   		 return childrenSumCheck(root->right);
    else return 0;
   }
   else if(root->key==root->left->key+root->right->key)
   	   return childrenSumCheck(root->left)&&childrenSumCheck(root->right);
   	else return 0;
}
void increment(node *root,int diff)
{
  if(root!=NULL)
  {
    if(root->left!=NULL)
    {
      root->left->key+=diff;
      increment(root->left,diff);
    }
    else if(root->right!=NULL)
    {
      root->right->key+=diff;
      increment(root->right,diff);
    }
  }
}
void covert_to_cspbt(node *root)
{
  if(root!=NULL)
  {
    covert_to_cspbt(root->left);
    covert_to_cspbt(root->right);
    int left=0,right=0;
    if(root->left!=NULL)
      left=root->left->key;
    if(root->right!=NULL)
      right=root->right->key;
    int data=left+right;
    int diff=data-root->key;
    if(diff>0)
      root->key=data;
    else increment(root,-1*diff);
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
int main()
{
	node *root=NULL;
	int key,c;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Check Children Sum Property\n4:Convert to CSPBT\n5:Exit\nEnter Choice:";
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
          case 3:key=childrenSumCheck(root);
                 if(key==1) cout<<"YES"<<endl;
                 else cout<<"NO"<<endl;
                 break;
          case 4:covert_to_cspbt(root);
                 break;
          case 5:return 0;
          default:cout<<"Please enter a valid choice.\n";
		}
	}
	return 0;
}