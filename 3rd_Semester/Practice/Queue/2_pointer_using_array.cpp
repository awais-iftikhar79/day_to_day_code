#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        Q = new int[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        Q = new int[this->size];
    }

    void enqueue(int value);
    int dequeue();
    void display();
    bool is_full();
    bool is_empty();
};
bool Queue::is_full()
{
    return (rear == size - 1);
}

bool Queue::is_empty()
{
    return (front == rear);
}

void Queue::enqueue(int value)
{

    if (is_full())
    {
        cout << "Queue is already Full!" << endl;
        return;
    }
    else
    {
        Q[++rear] = value;
    }
}
int Queue::dequeue()
{
    int x = -1;

    if (is_empty())
    {
        cout << "Queue is already empty !" << endl;
        return x;
    }
    else
    {
        x = Q[++front];
    }
    return x;
}

void Queue::display()
{
    if (is_empty())
    {
        cout << "Queue is empty !" << endl;
        return;
    }
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(6);

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);

    q.display();

    q.dequeue();

    q.display();
    cout << q.is_empty() << endl;

    return 0;
}