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
    list.display();

    return 0;
}