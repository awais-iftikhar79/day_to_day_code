#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class Doubly_list
{
private:
    Node *head;
    Node *tail;

public:
    Doubly_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_at_head(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;

        new_node->prev = nullptr;
        new_node->next = head;
        if (head)
        {
            head->prev = new_node;
        }
        else
        {
            tail = new_node;
        }
        head = new_node;
    }

    void insert_at_tail(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;

        new_node->next = nullptr;
        new_node->prev = tail;

        if (tail)
        {
            tail->next = new_node;
        }
        else
        {
            head = new_node;
        }
        tail = new_node;
    }

    void insert_at_any_pos(int index, int value)
    {
        if (index < 0 || index > count_nodes())
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        if (index == 0)
        {
            insert_at_head(value);
        }
        else if (index == count_nodes())
        {
            insert_at_tail(value);
        }
        else
        {
            Node *new_node = new Node;
            Node *p = head;

            new_node->data = value;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            if (p->next)
            {
                p->next->prev = new_node;
            }
            new_node->prev = p;
            p->next = new_node;
        }
    }

    int delete_at_head()
    {
        if (head)
        {
            int x = -1;
            Node *p = head;
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            x = p->data;
            delete (p);
            return x;
        }
        else
        {
            return -1;
        }
    }

    int delete_at_tail()
    {
        if (tail)
        {
            Node *p = tail;
            int x = p->data;
            tail = tail->prev;

            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }

            delete (p);
            return x;
        }
        else
        {
            return -1;
        }
    }

    int delete_at_Any_position(int index)
    {
        if (index < 0 || index > count_nodes())
        {
            cout << "Invalid Index !" << endl;
            return -1;
        }
        int x = -1;
        if (index == 0)
        {
            x = delete_at_head();
            return x;
        }
        else if (index == count_nodes() - 1)
        {
            x = delete_at_tail();
            return x;
        }
        else
        {
            Node *p = head;

            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            if (p->next)
            {
                p->next->prev = p->prev;
            }
            x = p->data;
            delete (p);
            return x;
        }
    }

    int count_nodes()
    {
        if (head == nullptr)
        {
            return 0;
        }
        Node *p = head;

        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Null" << endl;
        }
        Node *p = head;

        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void reverse_link()
    {
        Node *p = head;
        Node *temp = nullptr;
        tail = head;
        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;

            if (p->prev == nullptr)
            {
                head = p;
            }
            p = p->prev;
        }
    }
};
int main()
{
    Doubly_list list;
    list.insert_at_head(2);
    list.insert_at_head(4);
    list.insert_at_tail(8);
    list.insert_at_tail(6);
    list.insert_at_any_pos(4, 10);
    list.display();
    list.delete_at_Any_position(3);
    list.display();
    list.reverse_link();
    list.display();
    return 0;
}