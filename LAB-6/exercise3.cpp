#include<iostream>
using namespace std;

struct node
{
    int val;
    node* right;
    node* left;

    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

int maxDepth(node* root)
{
    if(root == NULL) return INT16_MAX;

    int lh = 1 + maxDepth(root -> left);
    int rh = 1 + maxDepth(root -> right);

    return max(lh,rh);
}

int minDepth(node* root)
{
    if(root == NULL) return INT16_MAX;

    int lh = 1 + minDepth(root -> left);
    int rh = 1 + maxDepth(root -> right);

    return min(lh,rh);
}

int isBST(node *root)
{
    if (root == NULL)
        return 1;
 
    //false if the max of the left is > than us
    if (root -> left != NULL && maxDepth(root -> left) >= root -> val)
        return 0;
 
    //false if the min of the right is <= than us
    if (root -> right != NULL && minDepth(root -> right) <= root -> val)
        return 0;
 
    // false if, recursively, the left or right is not a BST
    if (!isBST(root ->left) || !isBST(root -> right))
        return 0;
 
    //passing all that, it's a BST */
    return 1;
}

int main()
{
    node *root = new node(50);
    root -> left = new node(17);
    root -> left -> left = new node(12);
    root -> left -> left -> left = new node(9);
    root -> left -> left -> right = new node(14);
    root -> left -> right = new node(23);
    root -> left -> right -> right = new node(19);
    root -> right = new node(72);
    root -> right -> left = new node(54);
    root -> right -> left -> right = new node(67);
    root -> right -> right = new node(76);
    
    int h = isBST(root);
    if (h)
        printf("Is BST");
    else
        printf("Not a BST");
 
    return 0;

}