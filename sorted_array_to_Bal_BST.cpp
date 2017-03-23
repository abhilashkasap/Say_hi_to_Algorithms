#include<iostream> // sorted array to balanced bst 
#include<cstdlib>
using namespace std;


 

struct tree
{
    int data;
    tree *left;
    tree *right;
};
 

 tree* new_node(int data)
{
    tree *node = new tree;
    
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

struct tree* arraytobst(int arr[], int start, int end)
{
    
    if (start > end)
      return NULL;
     int mid = (start + end)/2;
    tree *root = new_node(arr[mid]);
    root->left =  arraytobst(arr, start, mid-1);
     root->right = arraytobst(arr, mid+1, end);
 
    return root;
}
 
void post_order(tree * node)
{
    if (node == NULL)
        return;
    
    post_order(node->left);
    post_order(node->right);
    cout<<node->data<<endl;
}
 

int main()
{
    int arr[] = {1,2,3,4,5,6,7,10,18};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    
    tree *root = arraytobst(arr, 0, n-1);
    printf("\n Post-order Traversal of constructed BST \n");
    post_order(root);
 
    return 0;
}
