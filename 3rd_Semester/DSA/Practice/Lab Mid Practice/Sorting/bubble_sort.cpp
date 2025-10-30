#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Singly_list
{
private:
    Node *head;
    Node *tail;

    void r_reverse_display(struct Node *p)
    {
        if (p == nullptr)
        {
            return;
        }
        r_reverse_display(p->next);
        cout << p->data << " ";
    }

    void recursive_reverve_link(struct Node *q, struct Node *p)
    {
        if (p)
        {
            recursive_reverve_link(p, p->next);
            p->next = q;
        }
        else
        {
            head = q;
        }
    }

public:
    Singly_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_at_head(int value)
    {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = head;
        head = new_node;

        if (tail == nullptr)
        {
            tail = new_node;
        }
    }

    void insert_at_tail(int value)
    {

        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            tail = head = new_node;
        }
        tail->next = new_node;
        tail = new_node;
    }

    void insert_at_index(int index, int value)
    {
        if (index < 0 || index > count_node())
        {
            cout << "Invalid Index !" << endl;
            return;
        }

        if (index == 0)
        {
            insert_at_head(value);
        }
        else if (index == count_node())
        {
            insert_at_tail(value);
        }
        else
        {
            Node *p = head;
            Node *new_node = new Node;

            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->data = value;
            new_node->next = p->next;
            p->next = new_node;
        }
    }

    int count_node()
    {
        if (head == nullptr)
            return 0;
        Node *p = head;
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    int delet_at_head()
    {
        if (head)
        {
            int x = -1;
            Node *q = head;
            head = head->next;
            x = q->data;
            delete (q);
            return x;
        }
        else
        {
            cout << "no Node is present" << endl;
            return -1;
        }
    }

    int delete_at_any_pos(int index)
    {
        if (index < 0 || index > count_node())
        {
            cout << "Invalid Index!" << endl;
            return -1;
        }
        int x = -1;
        if (index == 0)
        {
            x = delet_at_head();
            return x;
        }
        else
        {
            Node *p = head, *q = nullptr;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete (p);
            return x;
        }
    }

    void removeDuplicates()
    {
        Node *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {

                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else
            {

                current = current->next;
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

    void reverse_link()
    {
        Node *p = head, *q = nullptr, *r = nullptr;

        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }
    void reverse_display()
    {
        Node *p = head;
        r_reverse_display(p);
        cout << endl;
    }

    void recursive_reverve_link()
    {
        Node *p = head, *q = nullptr;
        recursive_reverve_link(q, p);
    }

    void bubble_sort()
    {
        if (head == nullptr)
        {
            return;
        }
        int count = count_node();
        for (int i = 0; i < count - 1; i++)
        {
            Node *p = head;
            for (int j = 0; j < count - 1 - i; j++)
            {
                if (p->data > p->next->data)
                {
                    int temp = p->next->data;
                    p->next->data = p->data;
                    p->data = temp;
                }
                p=p->next;
            }
        }
    }
};
int main()
{
    Singly_list list;
    list.insert_at_head(2);
    list.insert_at_head(4);
    list.insert_at_head(6);
    list.insert_at_tail(8);
    list.insert_at_index(4, 10);
    list.insert_at_tail(2);
    list.display();
    list.reverse_display();
    list.display();
    list.reverse_link();
    list.display();
    list.recursive_reverve_link();
    list.display();
    list.bubble_sort();
    //list.removeDuplicates(); // this works for sorted
    list.display();

    return 0;
}