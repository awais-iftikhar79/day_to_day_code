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

    int Rsum_elements(struct Node *p)
    {
        if (p == nullptr)
        {
            return 0;
        }
        else
        {
            return Rsum_elements(p->next) + p->data;
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

    int sum_elements()
    {
        Node *p = first;
        int sum = 0;
        while (p)
        {
            sum += p->data;
            p = p->next;
        }
        return sum;
    }

    int Rsum_elements() // recursive
    {
        return Rsum_elements(first);
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

    cout << "Sum of Elements (using loop): " << list.sum_elements() << endl;
    cout << "Sum of Elements (Recursion): " << list.Rsum_elements() << endl;

    return 0;
}