#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = nullptr; }

    bool is_empty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = top;
        top = new_node;
    }

    int pop()
    {
        Node *p = nullptr;
        int x = -1;

        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
        }
        else
        {
            x = top->data;
            p = top;
            top = top->next;
            delete (p);
        }
        return x;
    }

    void display()
    {
        Node *p = nullptr;

        p = top;

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
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    s.display();

    cout << s.pop() << endl;
    cout << s.is_empty() << endl;

    s.display();

    return 0;
}