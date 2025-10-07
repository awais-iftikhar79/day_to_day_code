#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5

class Stack
{
private:
    int top;
    char *A;

public:
    Stack()
    {
        top = -1;
        A = new char[MAX];
    }

    Stack(int size)
    {
        top = -1;
        A = new char[size];
    }

    bool is_full()
    {
        return (top == MAX - 1);
    }

    bool is_empty()
    {
        return (top == -1);
    }

    void push(char value)
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

    char pop()
    {
        char x = '\0';

        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return '\0';
        }
        else
        {
            x = A[top--];
        }
        return x;
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

    bool is_balance(char *exp)
    {
        for (int i = 0; i < strlen(exp); i++)
        {
            if (exp[i] == '(')
            {
                push(exp[i]);
            }
            if (exp[i] == ')')
            {
                if (is_empty())
                {
                    return false;
                }
                else
                {
                    pop();
                }
            }
        }
        return is_empty() ? 1 : 0;
    }
};
int main()
{
    char exp[] = "(a+b)*(c-d))";
    Stack s(strlen(exp));
    cout << s.is_balance(exp) << endl;

    return 0;
}