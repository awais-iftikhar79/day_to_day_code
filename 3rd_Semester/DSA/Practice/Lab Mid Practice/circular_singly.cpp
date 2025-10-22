#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Circular_s_list
{
private:
    Node *head;

public:
    Circular_s_list()
    {
        head = nullptr;
    }

    void insert_at_any_pos(int index, int value)
    {

        if (index < 0 || index > count_nodes())
        {
            cout << "Invalid Index !" << endl;
            return;
        }
        Node *new_node = new Node;
        Node *p = head;

        new_node->data = value;

        if (index == 0)
        {
            if (head == nullptr)
            {
                head = new_node;
                new_node->next = head;
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

    int count_nodes()
    {
        if (!head)
        {
            return 0;
        }
        int len = 0;
        Node *p = head;
        do
        {
            len++;
            p = p->next;
        } while (p != head);
        return len;
    }

    int delete_at_any_pos(int index)
    {
        if (!head)
        {
            cout << "List is empty !" << endl;
            return -1;
        }
        if (index < 0 || index >= count_nodes())
        {
            cout << "Invalid Index !" << endl;
            return -1;
        }
        Node *p, *q = nullptr;
        int x = -1;
        if (index == 0)
        {
            if (p->next == head)
            {
                x = head->data;
                delete (head);
                head = nullptr;
                return x;
            }
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = head->next;
            x = head->data;
            delete (head);
            head = p->next;
            return x;
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
            x = q->data;
            delete (q);
            return x;
        }
    }
};

int main()
{

    return 0;
}