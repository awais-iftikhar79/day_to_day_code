#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Circular_S_Linked
{
private:
    Node *head;

public:
    Circular_S_Linked()
    {
        head = nullptr;
    }

    void insert_node(int index, int value)
    {
        if (index < 0 || index > length())
        {
            cout << "Invalid Index!" << endl;
            return;
        }

        Node *new_node = new Node, *p = head;
        new_node->data = value;

        if (index == 0)
        {
            if (head == nullptr)
            {
                head = new_node;
                head->next = head;
                return;
            }
            do
            {
                p = p->next;
            } while (p->next != head);

            new_node->next = p->next;
            p->next = new_node;
            head = new_node;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            p->next = new_node;
        }
    }
    void delete_node(int index)
    {
        if (index < 0 || index >= length())
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        Node *p, *q = nullptr;
        if (index == 0)
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            if (p == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            p->next = head->next;
            delete head;
            head = p->next;
        }
        else
        {
            p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            q = p->next;
            p->next = q->next;

            delete q;
        }
    }

    int length()
    {
        Node *p = head;
        int len = 0;
        if (head == nullptr)
            return 0;
        do
        {
            len++;
            p = p->next;
        } while (p != head);

        return len;
    }

    void display()
    {
        Node *p = head;
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
};
int main()
{
    Circular_S_Linked list;
    list.insert_node(0, 1);
    list.insert_node(1, 2);
    list.insert_node(2, 3);
    list.insert_node(3, 4);
    list.insert_node(4, 5);

    list.display();

    list.delete_node(2);
    list.display();

    return 0;
}