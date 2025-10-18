#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5

class Stack
{
private:
    int top;
    int size;
    char *A;

public:
    Stack(int size = 100)
    {
        this->size = size;
        top = -1;
        A = new char[MAX];
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
            char ch = exp[i];

            if (ch == '(' || ch == '[' || ch == '{')
            {
                push(ch);
            }
            if (ch == ')' || ch == '}' || ch == ']')
            {
                if (is_empty())
                {
                    return false;
                }
                else
                {
                    char top_pop = pop();

                    if (ch == ')' && top_pop != '(' || ch == '}' && top_pop != '{' || ch == ']' && top_pop != '[')
                    {
                        return false;
                    }
                }
            }
        }
        return is_empty();
    }
};
int main()
{
    char exp[] = "{[(a+b)*(c-d)]}";
    Stack s(strlen(exp));
    cout << (s.is_balance(exp) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}