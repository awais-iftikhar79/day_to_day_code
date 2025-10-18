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
    void concatinate(Linked_List &l2)
    {
        Node *p = first;

        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = l2.first;
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
    Linked_List list1, list2;
    list1.insertion(0, 5);
    list1.insertion(1, 10);
    list1.insertion(2, 15);
    list1.insertion(0, 0);

    list1.display();

    list2.insertion(0, 9);
    list2.insertion(1, 18);
    list2.insertion(2, 28);
    list2.insertion(0, 1);

    list2.display();

    list1.concatinate(list2);
    list1.display();
    return 0;
}