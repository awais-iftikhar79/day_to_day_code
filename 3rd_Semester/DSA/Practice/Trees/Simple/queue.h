#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *l_child;
    Node *r_child;
};

class Queue
{
private:
    int size;
    int rear;
    int front;
    Node **Q;

public:
    Queue()
    {
        size = 10;
        front = 0; // it reuses all free spaces again and again
        rear = 0;
        Q = new Node *[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
        Q = new Node *[this->size];
    }

    void enqueue(Node *value);
    Node *dequeue();
    void display();
    bool is_full();
    bool is_empty();
};
bool Queue::is_full()
{
    return ((rear + 1) % size == front);
}

bool Queue::is_empty()
{
    return (front == rear);
}

void Queue::enqueue(Node *value)
{

    if (is_full())
    {
        cout << "Queue is already Full!" << endl;
        return;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = value;
    }
}
Node *Queue::dequeue()
{
    Node *x = nullptr;

    if (is_empty())
    {
        cout << "Queue is already empty !" << endl;
        return x;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

#endif