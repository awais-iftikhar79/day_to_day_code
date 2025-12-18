#ifndef LINKED_LIST_H
#define LINKED_LIST_H
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

public:
    Linked_List()
    {
        first = nullptr;
    }

    void insert_at_head(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;
        new_node->next = first;
        first = new_node;
    }

    Node *Lsearch(int key) // using loop
    {
        Node *p = first;
        while (p)
        {
            if (key == p->data)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    void display()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    };
};

#endif