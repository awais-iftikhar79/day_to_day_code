#include <iostream>
#include <climits>

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

    int Rmax_element(struct Node *p)
    {
        if (p == nullptr)
        {
            return INT_MIN;
        }
        int x = Rmax_element(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }

    int Rmin_element(struct Node *p)
    {
        if (p == nullptr)
        {
            return INT_MAX;
        }
        int x = Rmin_element(p->next);
        if (x < p->data)
        {
            return x;
        }
        else
        {
            return p->data;
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
    int max_element() // using loop
    {
        Node *p = first;
        int max = INT_MIN;
        while (p)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->next;
        }
        return max;
    }
    int Rmax_element() // recursive
    {
        return Rmax_element(first);
    }
    int min_element() // using loop
    {
        Node *p = first;
        int min = INT_MAX;
        while (p)
        {
            if (p->data < min)
            {
                min = p->data;
            }
            p = p->next;
        }
        return min;
    }
    int Rmin_element() // recursive
    {
        return Rmin_element(first);
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

    cout << "Max Element (using loop): " << list.max_element() << endl;
    cout << "Max Element (recursive): " << list.Rmax_element() << endl;
    cout << "Min Element (using loop): " << list.min_element() << endl;
    cout << "Min Element (recursive): " << list.Rmin_element() << endl;

    return 0;
}