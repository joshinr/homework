
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right; 
};

node *newNode(int key)
{
    node *tmp = new node();
    tmp->data = key;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

node* insert(node *root, int n)
{
    if(root == nullptr)
    {
        return newNode(n);
    }
    
    if (n <= root->data)
    {
        root->left = insert(root->left, n);
    }
    else 
    {
       root->right = insert(root->right, n);
    }
    
    return root;
}

void print_inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}

int main()
{
    node* root = nullptr;
    root = insert(root, 4);
    insert(root, 9);
    insert(root, 11);
    insert(root, 3);
    
    print_inorder(root);
    
    return 0;
}
