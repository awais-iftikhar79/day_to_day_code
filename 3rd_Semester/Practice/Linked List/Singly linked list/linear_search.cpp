#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first;

class Linked_List
{
private:
    Node *first;

    Node *R_Lsearch(struct Node *p, int key)
    {
        if (p == nullptr)
        {
            return nullptr;
        }
        if (key == p->data)
        {
            return p;
        }
        else
        {
            return R_Lsearch(p->next, key);
        }
    }

public:
    Linked_List()
    {
        first = nullptr;
    }

    void creation_of_nodes(int arr[], int size)
    {
        Node *new_node, *last; // last is for connecting previous node to next one (last->next = new node)
        first = new Node;

        first[0].data = arr[0];
        first[0].next = nullptr;

        last = first;

        for (int i = 1; i < size; i++)
        {
            new_node = new Node;

            new_node->data = arr[i];
            new_node->next = nullptr;

            last->next = new_node;
            last = new_node; // updating last by moving it one step forward
        }
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
        return NULL;
    }

    Node *R_Lsearch(int key)
    {
        return R_Lsearch(first, key);
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
    Node *temp, *temp2;
    int A[] = {1, 3, 5, 7, 9};

    list.creation_of_nodes(A, 5);
    list.display();

    temp = list.Lsearch(7);
    temp2 = list.R_Lsearch(7);
    if (temp)
    {
        cout << "Key Found (using loop): " << temp->data << endl;
    }
    else
    {
        cout << "Key not Found (using loop)" << endl;
    }
    if (temp2)
    {
        cout << "Key Found (using recursive) : " << temp2->data << endl;
    }
    else
    {
        cout << "Key not Found (using recursive)" << endl;
    }

    return 0;
}