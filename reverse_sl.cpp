#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Insert(int count)
{
    Node *head = new Node();
    head->data = 0;
    
    Node *tmp = head;
    for(int i=1; i<count; ++i)
    {
        tmp->next = new Node();
        tmp = tmp->next;
        tmp->data = i;
    }
    
    return head;
}

void Print(Node *node)
{
    while(node)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* Reverse(Node *node)
{
    Node *curr = node;
    Node *next = nullptr;
    Node *prev = nullptr;
    
    while(curr != nullptr)
    {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
    }
    
    return prev; 
}

int main()
{
    Node *head = Insert(10);
    Print(head);
    Node *reverseHead = Reverse(head);
    Print(reverseHead);
    return 0;
}

