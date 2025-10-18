#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    int top;
    int *A;

public:
    Stack()
    {
        top = -1;
        A = new int[MAX];
    }
    bool is_full()
    {
        return (top == MAX - 1);
    }

    bool is_empty()
    {
        return (top == -1);
    }

    void push(int value)
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

    void pop()
    {
        int x = -1;

        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        else
        {
            x = A[top--];
            cout << "Deleted Element is " << x << endl;
        }
    }
    void stack_top()
    {
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        else
        {
            cout << "Top element is : " << A[top] << endl;
        }
    }
    void display()
    {
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    }
    ~Stack()
    {
        delete[] A;
    }
};
int main()
{
    Stack s;

    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);

    s.display();

    s.pop();
    s.display();

    return 0;
}