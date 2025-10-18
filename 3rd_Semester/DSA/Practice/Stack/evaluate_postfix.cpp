#include <iostream>
#include <cstring>
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

    Stack(int size)
    {
        top = -1;
        A = new int[size];
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

    int pop()
    {
        char x = -1;
        ;

        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return x;
        }
        else
        {
            x = A[top--];
        }
        return x;
    }
    int stack_top()
    {
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
        else
        {
            return A[top];
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

int operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int precedance(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *inf_to_post(char *infix)
{
    Stack s;

    char *postfix;
    int length = strlen(infix);
    postfix = new char[length + 1];

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (operand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (s.is_empty() || (precedance(infix[i]) > precedance(s.stack_top())))
            {
                s.push(infix[i++]);
            }
            else
            {
                postfix[j++] = s.pop();
            }
        }
    }
    while (!s.is_empty())
    {
        postfix[j++] = s.pop();
    }
    postfix[j++] = '\0';

    return postfix;
}

int evaluate(char *postfix)
{
    Stack s1;
    int x1, x2, r;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (operand(postfix[i]))
        {
            s1.push(postfix[i] - '0');
        }
        else
        {
            x2 = s1.pop();
            x1 = s1.pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;

            default:
                break;
            }
            s1.push(r);
        }
    }
    return s1.stack_top();
}

int main()
{
    string input;
    cout << "Enter expression" << endl;
    getline(cin, input);

    char infix[100];
    strcpy(infix, input.c_str());

    char *postfix = inf_to_post(infix);
    cout << postfix << endl;
    cout << evaluate(postfix) << endl;

    return 0;
}