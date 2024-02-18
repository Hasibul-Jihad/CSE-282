#include<iostream>
#include "bst.h"
using namespace std;

 vector<int>LevelOrderRight(node* root)
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
            
        }

        if(temp -> right != NULL)
        {
            q.push(temp -> right);
            v.push_back(temp -> right -> val);
        }
    }

    return v;
}

int main()
{
    
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root  -> left -> left -> left = new node(5);
    root  -> left -> right = new node(6);

    vector<int> righty = LevelOrderRight(root);
    cout<<"the right childs are:";
    for(int i = 0; i < righty.size();i++)
    {
        cout<<righty[i]<<" ";
    }
    
    return 0;
}