
#include <stdio.h>
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

node* in_order_successor(node *root)
{   
    node *curr = root;
    
    while(curr->left != nullptr)
    {   
        curr = curr->left;
    }
    return curr;
}

node *deteteNode(node *root, int key)
{
    // base case
    if (root == NULL) return root;
    
    if (key < root->data)
    {
        root->left = deteteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deteteNode(root->right, key);
    }
    else
    {
        if(root->left == nullptr)
        {
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == nullptr)
        {
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            node *tmp = in_order_successor(root->right);
            root->data = tmp->data;
            root->right = deteteNode(root->right, tmp->data);
            return root;
        }
    }

    return root;
}

int main(int argc, char **argv)
{
    node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 55);

    print_inorder(root);
    root = deteteNode(root, 50);
    cout<<endl;
    print_inorder(root);
    
    return 0;
}