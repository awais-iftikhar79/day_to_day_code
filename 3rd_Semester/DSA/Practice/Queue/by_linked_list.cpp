#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() { front = nullptr, rear = nullptr; }
    void enqueue(int value);
    int dequeue();
    void display();
    bool is_empty();
};

void Queue::enqueue(int value)
{
    Node *new_node = new Node;

    new_node->data = value;
    new_node->next = nullptr;

    if (front == nullptr)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

bool Queue::is_empty()
{
    return (front == nullptr);
}
int Queue::dequeue()
{
    int x = -1;
    if (is_empty())
    {
        cout << "Queu is empty !" << endl;
        return x;
    }
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;
        delete (p);
        return x;
    }
}

void Queue::display()
{
    Node *p = front;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);

    q.display();

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.display();

    return 0;
}