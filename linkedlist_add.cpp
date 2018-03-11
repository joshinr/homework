#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* Insert(Node *node, int data)
{
    if (node == nullptr)
    {
        node = new Node();
        node->data = data;
        node->next = nullptr;
    }
    else
    {
        node->next = new Node();
        node = node->next;
        node->data = data;
    }
    return node;
}

Node* Reverse(Node *node)
{
    Node *current = node;
    Node *curr = node;
    Node *next = nullptr;
    Node *prev = nullptr;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void Print(Node *head)
{
    Node *tmp = head;
    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void BasicTest()
{
    Node *head = nullptr;
    Node *current = nullptr;

    head = Insert(head, 1);
    current = head;

    current = Insert(current, 2);
    current = Insert(current, 3);
    current = Insert(current, 4);
    current = Insert(current, 5);

    Print(head);
    head  = Reverse(head);
    Print(head);
}

Node* Add(Node *n1, Node *n2)
{
    Node *n3 = nullptr;
    Node *curr = nullptr;
    int sum = 0;
    while(n1 != nullptr || n2 != nullptr)
    {
       if (n1 != nullptr)
       {
            sum += n1->data;
            n1 = n1->next;    
       }
       if (n2 != nullptr)
       {
            sum += n2->data;
            n2 = n2->next;    
       }

       int div = sum % 10; 
       sum = sum / 10;
       if (n3 == nullptr)
       {
           n3 = new Node();
           n3->data = div;
           n3->next = nullptr;
           curr = n3;
       }
       else
       {
           curr->next = new Node();
           curr = curr->next;
           curr->data = div;
           curr->next = nullptr;
       }
    }

    return n3;
}

void AdditionTest()
{
    Node *head = nullptr;
    Node *current = nullptr;

    head = Insert(head, 9);
    current = head;

    current = Insert(current, 8);

    Node *head1 = nullptr;
    Node *current1 = nullptr;

    head1 = Insert(head1, 1);
    current1 = head1;

    Node *tmp = Add(head, head1);
    Print(tmp);

}

int main()
{
//    BasicTest();
    AdditionTest();
    return 0;
}
