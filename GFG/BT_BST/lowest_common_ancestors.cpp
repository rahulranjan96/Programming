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
node* lca(node *root,int val1,int val2)
{
	if(root==NULL) return NULL;
	if(root->key==val1||root->key==val2) return root;
	node *lt_lca=lca(root->left,val1,val2);
	node *rt_lca=lca(root->right,val1,val2);
	if(lt_lca!=NULL&&rt_lca!=NULL) return root;
	else if(lt_lca==NULL) return rt_lca;
	else return lt_lca;
}
int main()
{
	int c,key,val1,val2;
	node *root=NULL,*temp=NULL;
	while(1)
	{
		cout<<"1:Insert\n2:LCA\n3:Exit\nEnter Choice:";
		cin>>c;
        switch(c)
        {
        	case 1:cout<<"Enter key to be inserted:";
        	       cin>>key;
        	       root=insert(root,key);
        	       break;
        	case 2:cout<<"Enter two key values whose lowest common ancestors are to be found:";
        	       cin>>val1>>val2;
        	       temp=lca(root,val1,val2);
        	       cout<<temp->key<<endl;
        	       break;
        	case 3:return 0;
        	default:cout<<"Please enter a valid choice\n";
        }
	}
	return 0;
}


/*
1:Abhishek Tyagi
2:Siddhartha Khabia
3:Nitish Garg
4:Sagar Manchanda
5:Geetesh Tabjul
6:Nikhil Yadala
7:Abhishek Yadav
8:Sambhav Kothari
9:Vistar Juneja
10:Sangana Abhiram
11:Amogh Shankar Gupta
12:Kevin Pandya
13:Rahul Kant
14:Yash Pote
15:Manoj Ghuhan
16:Anish V Monsy
*/