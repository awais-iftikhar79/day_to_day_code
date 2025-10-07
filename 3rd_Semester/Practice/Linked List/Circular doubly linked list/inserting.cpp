#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class CircularDoublyLinked
{
private:
    Node *head;
    Node *tail;

public:
    CircularDoublyLinked()
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

        Node *new_node = new Node, *p = head;
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
            head->prev = new_node;
            tail->next = new_node;
            return;
        }
        else if (index == length())
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
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            p->next->prev = new_node;
            new_node->prev = p;
            p->next = new_node;
        }
    }

    int length()
    {
        int len = 0;
        if (head == nullptr)
        {
            return 0;
        }
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
        Node *p = head;
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
    CircularDoublyLinked list;
    list.insert(3, 0);
    list.insert(6, 1);
    list.insert(9, 2);
    list.display();
    list.insert(0, 1);
    list.display();

    return 0;
}