#include<iostream>
#include "bst.h"
using namespace std;

int maxDepth(node* root)
{
    if(root == NULL) return 0;

    int lh = maxDepth(root -> left);
    int rh = maxDepth(root -> right);

    return (1 + max(lh,rh));

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
    
    int h = maxDepth(root);
    cout<<"the height of the tree is:"<<h<<endl;

    return 0;

}