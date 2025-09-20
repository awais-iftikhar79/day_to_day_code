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
    int Rcount_nodes(struct Node *p)
    {
        if (p == nullptr)
        {
            return 0;
        }
        else
        {
            return Rcount_nodes(p->next) + 1;
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

    int count_nodes() // by using loop
    {
        Node *p = first;
        int lenght = 0;

        while (p)
        {
            lenght++;
            p = p->next;
        }
        return lenght;
    }

    int Rcount_nodes()  //recursive 
    {
        return Rcount_nodes(first);
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
    int A[] = {1, 3, 5, 7, 9};

    list.creation_of_nodes(A, 5);
    list.display();
    cout << "Number of Nodes (using loop): " << list.count_nodes() << endl;
    cout << "Number of Nodes (recursive): " << list.Rcount_nodes() << endl;

    return 0;
}