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

    void insertion(int index, int value)
    {
        if (index < 0 || index > count_nodes())
        {
            cout << "index is invalid !" << endl;
            return;
        }
        Node *new_node = new Node, *p;

        if (index == 0)
        {
            new_node->data = value;
            new_node->next = first;
            first = new_node;
        }
        else
        {
            p = first;

            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }

            new_node->data = value;
            new_node->next = p->next;
            p->next = new_node;
        }
    }

    void delete_node(int index)
    {
        Node *p = first, *q = NULL;
        if (index < 0 || index > count_nodes())
        {
            cout << "Invalid Index !" << endl;
            return;
        }
        if (index == 0)
        {
            q = first;
            first = first->next;

            delete q;
        }
        else
        {
            for (int i = 0; i < index - 1 && p; i++)
            {
                q = p;
                p = p->next;
            }
            if (p)
            {
                q->next = p->next;
                delete p;
            }
        }
    }

    void remove_duplicate()
    {
        Node *p = first, *q = p->next;
        while (q != nullptr)
        {
            if (p->data != q->data)
            {
                p = q;
                q = p->next;
            }
            else
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
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
    list.insertion(0, 5);
    list.insertion(1, 10);
    list.insertion(2, 10);
    list.insertion(3, 20);
    list.insertion(0, 0);
    list.display();
    list.remove_duplicate();
    list.display();

    return 0;
}