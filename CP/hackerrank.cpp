#include <iostream>
#include <cstdio>
using namespace std;

int k=0;

typedef struct node{
    long long int val;
    struct node* left;
    struct node* right;
    long long int ht;
    long long int num_left;
    long long int num_right;
}node;

long long int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->ht;
}
 
// A utility function to get maximum of two integers
long long int max(long long int a, long long int b)
{
    return (a > b)? a : b;
}
 
long long int num_count(node *root)
{
    if(root==NULL)
        return -1;
    else return root->num_left+root->num_right;
}
/* Helper function that allocates a new node with the given val and
    NULL left and right pointers. */
node* newNode(long long int val)
{
    node* root = new node[1];
    root->val   = val;
    root->left   = NULL;
    root->right  = NULL;
    root->ht = 1;  // new node is initially added at leaf
    root->num_left=0;
    root->num_right=0;
    return(root);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
node *rightRotate(node *y)
{
    long long int num=y->left->num_right;
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
    x->num_right=1+y->num_right+num;
    y->num_left=num;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    long long int num=x->right->num_left;
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
    y->num_left=1+x->num_left+num;
    x->num_right=num;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
long long int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
node* insert(node* root, long long int val)
{
    /* 1.  Perform the normal BST rotation */
    if (root == NULL)
        return(newNode(val));
 
    if (val < root->val)
        root->left  = insert(root->left, val);
    else
        root->right = insert(root->right, val);
 
    /* 2. Update height of this ancestor node */
    root->ht = max(height(root->left), height(root->right)) + 1;
    root->num_left=num_count(root->left)+1;
    root->num_right=num_count(root->right)+1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    long long int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && val > root->left->val)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    /* return the (unchanged) node pointer */
    return root;
}

node * minValueNode(node* root)
{
    node* current = root;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

node* deleteNode(node* root, long long int val)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the val to be deleted is smaller than the root's val,
    // then it lies in left subtree
    if ( val < root->val )
        root->left = deleteNode(root->left, val);
 
    // If the val to be deleted is greater than the root's val,
    // then it lies in right subtree
    else if( val > root->val )
        root->right = deleteNode(root->right, val);
 
    // if val is same as root's val, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            node *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child
 
            delete(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->val = temp->val;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->ht = max(height(root->left), height(root->right)) + 1;
    root->num_left=num_count(root->left)+1;
    root->num_right=num_count(root->right)+1;
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    long long int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

bool search(node *root,long long int val)
{
    if(root==NULL)
        return false;
    else if(root->val==val)
        return true;
    else if(root->val>val)
        return search(root->left,val);
    else return search(root->right,val);
}

void display(node *ptr, long long int level,node *root)

    {
        long long int i;
        if (ptr!=NULL)
        {
            display(ptr->right, level + 1,root);
            cout<<endl;
            if (ptr == root)
            cout<<"Root -> ";
            for (i = 0; i < level && ptr != root; i++)
                cout<<"        ";
            cout<<ptr->val<<"("<<getBalance(ptr)<<")"<<"["<<ptr->ht<<"]"<<"{"<<ptr->num_left<<","<<ptr->num_right<<"}";
            display(ptr->left, level + 1,root);

        }

    }

node *inorder1(node *root,int n)
{
    
    if(root!=NULL)
    {
        inorder1(root->left,n);
        if(k==n) return root;
        k++;
        inorder1(root->right,n);
    }
    
}

node *inorder2(node *root,int n)
{
    
    if(root!=NULL)
    {
        inorder2(root->left,n);
        if(k==n) return root;
        k++;
        inorder2(root->right,n);
    }
}

int main()
{
    long long int choice,data,n,val,q,n1,n2,sum;
    cin>>q;
    char c;
    bool cond;
    node *root=NULL;
    node *node1,*node2;
    while(q--)
    {
        cin>>c>>val;
        if(c=='a')
        {
           root=insert(root,val);
            n1=root->num_left;
            n2=root->num_right;
            n=n1+n2+1;
            if(n%2==0)
            {
                k=0;
                node1=inorder1(root,n/2);
                k=0;
                node2=inorder2(root,n/2-1);
                sum=node1->val+node2->val;
                if(sum%2==0)
                    cout<<sum/2<<endl;
                else printf("%0.1f\n",(float)sum/2);
            }
            else
            {
               k=0;
                node1=inorder1(root,n/2);
                sum=node1->val;
                    cout<<sum<<endl; 
            }


        }
        else if(c=='r')
        {
            cond=search(root,val);
            if(cond==false) 
                cout<<"Wrong!"<<endl;
            else
            {
             root=deleteNode(root,val);
             if(root==NULL)
                 cout<<"Wrong!"<<endl;
             else
             {
              n1=root->num_left;
              n2=root->num_right;
              n=n1+n2+1;
              if(n%2==0)
             {
                k=0;
                node1=inorder1(root,n/2);
                k=0;
                node2=inorder2(root,n/2-1);
                sum=node1->val+node2->val;
                if(sum%2==0)
                    cout<<sum/2<<endl;
                else printf("%0.1f\n",(float)sum/2);
             }
             else
             {
               k=0;
                node1=inorder1(root,n/2);
                sum=node1->val;
                    cout<<sum<<endl; 
             }
             }
            }
        }
           /*cout<<endl;
        display(root,1,root);
            cout<<endl;*/
    }
    return 0;
}