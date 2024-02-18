/*To check if a Binary tree is balanced we need to check three conditions :
1. The absolute difference between heights of left and right subtrees at any node should be less than 1.
2. For each node, its left subtree should be a balanced binary tree. 
3. For each node, its right subtree should be a balanced binary tree*/

#include<iostream>
#include "bst.h"
using namespace std;

int maxDepth(node* root)
{

    if(root == NULL) return 0;

    int lh = 1 + maxDepth(root -> left);
    if(lh == -1) return -1;

    int rh = 1 + maxDepth(root -> right);
    if(rh == -1) return -1;

    if(abs(lh - rh)>1) return -1;

    return max(lh,rh);
}

bool isBalanced(node* root)
{
    return (maxDepth(root) != -1);
}

int main()
{
    node* root = new node(1);
    root -> left = new node(2);
    root -> left -> left = new node(4);

    int h = isBalanced(root);

    if(h == 0)
    {
        cout<<"tree is not balanced"<<endl;
    }

    else{
        cout<<"tree is balanced"<<endl;
    }

    return 0;
    
}

