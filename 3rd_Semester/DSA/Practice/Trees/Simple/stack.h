#ifndef STACK_H
#define STACK_H
#include "queue.h"
#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size = 5;
    Node **A;

public:
    Stack()
    {
        top = -1;
        A = new Node *[size];
    }

    Stack(int size)
    {
        this->size = size;
        top = -1;
        A = new Node *[size];
    }

    bool is_full()
    {
        return (top == size - 1);
    }

    bool is_empty()
    {
        return (top == -1);
    }

    void push(Node *value)
    {
        if (is_full())
        {
            cout << "Stack is Full !" << endl;
            return;
        }
        else
        {
            A[++top] = value;
        }
    }

    Node *pop()
    {
        Node *x = nullptr;

        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return x;
        }
        else
        {
            x = A[top--];
            return x;
        }
    }

    ~Stack()
    {
        delete[] A;
    }
};

#endif