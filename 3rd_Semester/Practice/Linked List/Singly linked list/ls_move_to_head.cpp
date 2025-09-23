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

    Node *move_to_head(int key) // Linear Search and move that element to head
    {
        Node *p = first, *q = nullptr;
        while (p != nullptr)
        {
            if (key == p->data)
            {
                q->next = p->next;
                p->next = first;
                first = p;
                return p;
            }
            q = p;
            p = p->next;
        }
        return nullptr;
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
    Node *temp;
    int A[] = {1, 3, 5, 7, 9};

    list.creation_of_nodes(A, 5);
    list.display();

    temp = list.move_to_head(5);

    if (temp)
    {
        cout << "Key Found (using loop): " << temp->data << endl;
    }
    else
    {
        cout << "Key not Found (using loop)" << endl;
    }
    
    list.display();
    return 0;
}