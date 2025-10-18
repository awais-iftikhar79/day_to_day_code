#include <iostream>
#include <cstring>
using namespace std;

#define MAX 20

class Stack
{
private:
    int top;
    char *A;  // change from int* to char*

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
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return '\0';
        }
        else
        {
            return A[top--];
        }
    }
    char stack_top()
    {
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return '\0';
        }
        else
        {
            return A[top];
        }
    }
    ~Stack()
    {
        delete[] A;
    }
};


int operand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')');
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else
        return 0;
}


char *inf_to_post(char *infix)
{
    int length = strlen(infix);
    Stack s(length);
    char *postfix = new char[length + 1];
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];

        if (operand(c))
        {
            // If it's operand, add to postfix
            postfix[j++] = c;
            i++;
        }
        else
        {
            if (c == '(')
            {
                s.push(c);
                i++;
            }
            else if (c == ')')
            {
                // Pop until '(' is found
                while (!s.is_empty() && s.stack_top() != '(')
                {
                    postfix[j++] = s.pop();
                }
                if (!s.is_empty() && s.stack_top() == '(')
                {
                    s.pop(); // Remove '(' from stack
                }
                i++;
            }
            else
            {
                // For operators (+, -, *, /, ^)
                // Handle right associativity of '^'
                while (!s.is_empty() && s.stack_top() != '(' &&
                       ((precedence(c) < precedence(s.stack_top())) ||
                        (precedence(c) == precedence(s.stack_top()) && c != '^')))
                {
                    postfix[j++] = s.pop();
                }
                s.push(c);
                i++;
            }
        }
    }

    // Pop remaining operators
    while (!s.is_empty())
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; // null terminate
    return postfix;
}

int evaluate_postfix(char *postfix)
{
    int length = strlen(postfix);
    Stack s(length);

    int i = 0;

    while (postfix[i] != '\0')
    {
        char c = postfix[i];

        if (operand(c))
        {
            // Assuming operands are digits '0' to '9'
            s.push(c - '0'); // Convert char to int and push
        }
        else
        {
            // Operator encountered, pop two operands
            int val2 = s.pop();
            int val1 = s.pop();

            int result = 0;

            switch (c)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                if (val2 != 0)
                    result = val1 / val2;
                else
                {
                    cout << "Division by zero error!" << endl;
                    return 0; // or handle error
                }
                break;
            case '^':
                result = 1;
                for (int k = 0; k < val2; k++)
                    result *= val1;
                break;
            default:
                cout << "Unknown operator: " << c << endl;
                return 0;
            }

            s.push(result);
        }

        i++;
    }

    // Result is at the top of stack
    return s.pop();
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
    cout << evaluate_postfix(postfix) << endl;

    return 0;
}