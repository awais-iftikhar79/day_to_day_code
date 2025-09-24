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

    void sort_insert(int value)
    {
        Node *p = first, *q = nullptr, *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;

        if (first == nullptr)
        {
            first = last = new_node;
        }
        else
        {
            while (p && p->data < value)
            {
                q = p;
                p = p->next;
            }
            if (p == first)
            {
                new_node->next = first;
                first = new_node;
            }
            else
            {
                new_node->next = q->next;
                q->next = new_node;
            }
            if (new_node->next == nullptr)
            {
                last = new_node;
            }
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
    list.display();
    list.sort_insert(5);
    list.sort_insert(0);
    list.sort_insert(10);
    list.display();

    return 0;
}