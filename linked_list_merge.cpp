// Example program
#include <iostream>
#include <string>


using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Insert(int count, int num)
{
    Node *head = new Node();
    head->data = num;
    
    Node *tmp = head;
    for(int i=0; i<count; ++i)
    {
        tmp->next = new Node();
        tmp = tmp->next;
        tmp->data = ++num;
    }
    
    return head;
}

void Print(std::string pre, Node *node)
{
    cout<<endl;
    cout << pre << " ";
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

Node *Merge(Node *a, Node *b)
{
    Node *result = nullptr;
    
    Print("a", a);
    Print("b", b);
    
    
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
        
    if (a->data <= b->data)
    {
        result = a;
        Print("result", result);
        a->next = Merge (a->next, b);
    }
    else
    {
        result = b;
        Print("result", result);
        b->next = Merge(b->next, a);
    }
        
    return result;
        
}

int main()
{
    Node *a = Insert(2, 5);
    Node *b = Insert(2, 1);
    
    Print("a", a);
    Print("b", b);
    
    Print("Merge", Merge(a, b));
    
    return 0;
}
