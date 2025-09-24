#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
private:
    Node *first;
    Node *last;

public:
    Linked_List()
    {
        first = nullptr;
        last = nullptr;
    }
    
    void insert_at_head(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;
        new_node->next = first;
        first = new_node;

        if (last == nullptr)
        {
            last = new_node;
        }
    }

    void insert_at_tail(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;
        new_node->next = nullptr;

        if (first == nullptr)
        {
            first = last = new_node;
        }
        else
        {
            last->next = new_node;
            last = new_node;
        }
    }

    void display()
    {
        Node *p = first;
        while (p != nullptr)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Linked_List list;
    list.insert_at_head(5);
    list.display();
    list.insert_at_head(10);
    list.display();
    list.insert_at_head(15);
    list.display();
    list.insert_at_tail(0);
    list.display();
    list.insert_at_tail(-5);
    list.display();

    return 0;
}