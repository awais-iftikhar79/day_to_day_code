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

    void insert_Array(int A[], int n)
    {
        Node *new_node, *last;

        head = new Node;
        head->data = A[0];
        head->next = head;
        last = head;

        for (int i = 1; i < n; i++)
        {
            new_node = new Node;
            new_node->data = A[i];
            new_node->next = last->next;
            last->next = new_node;
            last = new_node;
        }
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
    int A[5] = {1, 2, 3, 4, 5};

    list.insert_Array(A, 5);
    list.display();

    return 0;
}