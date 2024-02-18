#include<iostream>
using namespace std;

struct node
{
    node *left;
    node *right;
    int val;

    node(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

int maxDepth(node *root)
{
    if(root == nullptr) return 0;

    int lh = 1 + maxDepth(root -> left);
    if(lh == -1) return -1;

    int rh = 1 + maxDepth(root -> right);
    if(rh == -1) return -1;

    if(abs(lh - rh)>1) return -1;

    return max(lh , rh);
}

bool isBalanced(node *root)
{
    return maxDepth(root) != -1;
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
    
    int h = isBalanced(root);

    if( h == 0)  cout<<"not balanced ";
    else cout<<"is balanced";

    return 0;
}