#include<iostream>
#include "bst.h"
using namespace std;

 vector<int>LevelOrderLeft(node* root)
{
    if(root == NULL)
    {
        cout<<"tree is empty"<<endl;
    }

    queue<node*> q;
    q.push(root);

    vector<int> v;
    while(!q.empty()){
        node* temp =q.front();
        q.pop();

        if(temp -> left != NULL)
        {
            q.push(temp -> left);
            v.push_back(temp -> left -> val);
            
        }

        if(temp -> right != NULL)
        {
            q.push(temp -> right);
            
        }
    }

    return v;
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

    vector<int> lefty = LevelOrderLeft(root); 

    int sum = 0;

    for(int i = 0; i < lefty.size();i++)
    {
        sum = sum + lefty[i];
    }

    cout<<"the sum of the left child in a tree is :"<<sum<<endl;
    
    return 0;
}