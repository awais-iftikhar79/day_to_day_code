#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class Circular_d_list
{
private:
    Node *head;
    Node *tail;

public:
    Circular_d_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_at_any_pos(int index, int value)
    {
        if (index < 0 || index > count_nodes())
        {
            cout << "invalid Index !" << endl;
            return;
        }
        Node *new_node = new Node;
        new_node->data = value;

        if (index == 0)
        {
            if (head == nullptr)
            {
                head = tail = new_node;
                new_node->next = head;
                new_node->prev = head;
                return;
            }
            new_node->next = head;
            new_node->prev = tail;
            tail->next = new_node;
            head->prev = new_node;
            head = new_node;
            return;
        }
        else if (index == count_nodes())
        {
            new_node->next = head;
            new_node->prev = tail;
            tail->next = new_node;
            head->prev = new_node;
            tail = new_node;
            return;
        }
        else
        {
            Node *p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            p->next->prev = new_node;
            new_node->prev = p;
            p->next = new_node;
            return;
        }
    }

    int delete_at_Any_pos(int index)
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
        int x;
        Node *p = nullptr;
        if (index == 0)
        {
            if (head == tail)
            {
                x = head->data;
                delete (head);
                head = tail = nullptr;
                return x;
            }
            p = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            x = p->data;
            delete (p);
            return x;
        }
        else if (index == count_nodes() - 1)
        {
            p = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            x = p->data;
            delete (p);
            return x;
        }
        else
        {
            p = head;
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            x = p->data;
            delete (p);
            return x;
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

    void display()
    {
        if (!head)
        {
            cout << "List is empty !" << endl;
            return;
        }
        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout<<endl;
    }
};

int main()
{
    Circular_d_list list;
    list.insert_at_any_pos(0,1);
    list.insert_at_any_pos(1,2);
    list.insert_at_any_pos(2,3);
    list.insert_at_any_pos(3,4);
    list.display();
    list.delete_at_Any_pos(3);
    list.display();

    return 0;
}