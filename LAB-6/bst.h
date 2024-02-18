#include<bits/stdc++.h>
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

void InOrder(node* main){
    if(main == NULL) return;

    InOrder(main->left);
    cout<<main->val<<" ";
    InOrder(main->right);
    
}

void PreOrder(node* main){
    if(main == NULL) return;

    cout<<main->val<<" ";
    PreOrder(main->left);
    PreOrder(main->right);

}

void PostOrder(node* main){
    if (main == NULL) return;

    PostOrder(main->left);
    PostOrder(main->right);
    cout <<main->val << " ";

}

void LevelOrder(node *main) {
    if (main == NULL) return;

    queue<node*> q;
    q.push(main);

    while (!q.empty()) {
        node *temp = q.front();
        cout << temp->val<< " ";
        q.pop();

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

void StackPreOrder(node* main)
{
	// Base Case
	if (main == NULL) return;

	stack<node*> s;
	s.push(main);

	while (!s.empty()) {
		node *temp = s.top();
		cout<< temp->val<<" ";
		s.pop();

		if (main->right) s.push(main->right);
		if (main->left) s.push(main->left);
	}
}

