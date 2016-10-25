#include <iostream>
using namespace std;

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
    int ht;
}node;

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->ht;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given val and
    NULL left and right pointers. */
node* newNode(int val)
{
    node* root = new node[1];
    root->val   = val;
    root->left   = NULL;
    root->right  = NULL;
    root->ht = 1;  // new node is initially added at leaf
    return(root);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
node* insert(node* node, int val)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(val));
 
    if (val < node->val)
        node->left  = insert(node->left, val);
    else
        node->right = insert(node->right, val);
 
    /* 2. Update height of this ancestor node */
    node->ht = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && val > node->left->val)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && val < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
void display(node *ptr, int level,node *root)

    {
        int i;
        if (ptr!=NULL)
        {
            display(ptr->right, level + 1,root);
            cout<<endl;
            if (ptr == root)
            cout<<"Root -> ";
            for (i = 0; i < level && ptr != root; i++)
                cout<<"        ";
            cout<<ptr->val<<"("<<getBalance(ptr)<<")"<<"["<<ptr->ht<<"]";
            display(ptr->left, level + 1,root);

        }

    }

int main()
{
    int choice,data;
    node *root=NULL;
    while(1)
    {
        cout<<"1:Insert\n2:Exit\nEnter Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter value:";cin>>data;
                   root=insert(root,data);
                   cout<<endl;
                   display(root,1,root);
                   cout<<endl;
                   break;
            case 2:return 0;
        }
    }
    return 0;
}