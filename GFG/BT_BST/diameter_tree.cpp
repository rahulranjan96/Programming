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
int max3(int a,int b,int c)
{
	if(a>=b&&a>=c)
		return a;
	else if(b>=a&&b>=c)
		return b;
	else return c;
}
int max2(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}
int height(node *root)
{
	if(root!=NULL)
		return 1+max2(height(root->left),height(root->right));
	else return 0;
}
int diameter(node *root)   //O(n^2)
{
	if(root!=NULL)
	{
		int lt_height=height(root->left);
		int rt_height=height(root->right);
		int diameter_root=1+lt_height+rt_height;
		int left_diameter=diameter(root->left);
		int right_diameter=diameter(root->right);
		return max3(diameter_root,left_diameter,right_diameter);
	}
	else return 0;
}
int diameterOPTIMIZED(node *root,int *height)   //O(n)
{
   if(root!=NULL)
   {
   	int lh=0,rh=0;
   	int left_diameter=diameterOPTIMIZED(root->left,&lh);
   	int right_diameter=diameterOPTIMIZED(root->right,&rh);
   	*height=1+max2(lh,rh);
   	int diameter_root=1+lh+rh;
   	return max3(diameter_root,left_diameter,right_diameter);
   }
   else
   {
   	*height=0;
   	return 0;
   }
}
int main()
{
	int c,key,height=0;
	node *root=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:Diameter\n3:Diameter Optimize\n4:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<diameter(root)<<endl;
        	       break;
        	case 3:height=0;
        	       cout<<diameterOPTIMIZED(root,&height)<<endl;
        	       break;
        	case 4:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}