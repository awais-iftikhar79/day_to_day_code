#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinked
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinked()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value, int index)
    {
        if (index < 0 || index > length())
        {
            cout << "Invalid Index !" << endl;
            return;
        }

        Node *new_node = new Node;
        new_node->data = value;

        if (index == 0)
        {
            new_node->prev = nullptr;
            new_node->next = head;
            if (head != nullptr)
            {
                head->prev = new_node;
            }
            head = new_node;
        }
        else
        {
            Node *p = head;
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

    int length()
    {
        int len = 0;
        Node *p = head;

        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void delete_node(int index)
    {
        if (index < 1 || index > length())
        {
            cout << "Invalid Index !" << endl;
            return;
        }
        Node *p = nullptr;
        if (index == 1)
        {
            p = head;
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            delete (p);
        }
        else
        {
            p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            if (p->next)
            {
                p->next->prev = p->prev;
            }
            delete (p);
        }
    }
    void reversing_list()
    {
        Node *p = head;
        Node *temp = nullptr;

        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;

            if (p &&  p->next == nullptr)
            {
                head = p;
            }
        }
    }

    void display()
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinked list;
    list.insert(5, 0);
    list.display();
    list.insert(10, 1);
    list.display();
    list.insert(15, 2);
    list.display();
    list.insert(20, 3);
    list.display();
    list.reversing_list();
    list.display();

    return 0;
}