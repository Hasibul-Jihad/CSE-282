#include<iostream>
#include "bst.h"
using namespace std;

int maxDepth(node* root)
{
    if(root == NULL) return 0;

    int lh = maxDepth(root -> left);
    int rh = maxDepth(root -> right);

    return 1 + max(lh,rh);

}

bool isPerfect (node *root) {
    if (root == nullptr) return true;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return (lh == rh);
}
int main()
{

    node* root =new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left =new node(6);
    root -> right -> right = new node(7);
    root -> left -> left -> left = new node(9);

    int h = maxDepth(root);
    cout<<"the height of the tree is:"<<h<<endl;

    int c = isPerfect(root);
    if(c == 1)
    {
        cout<<"\nperfect"<<endl;
    }

    else
    {
        cout<<"\nnot perfect"<<endl;
    }

    return 0;
}