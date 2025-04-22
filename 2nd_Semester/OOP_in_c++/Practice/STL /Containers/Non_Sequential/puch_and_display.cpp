#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void display(stack<T> s)
{
    cout << "Elements is stack are : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    int n, size;

    cout << "Enter size of stack " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element in stack " << endl;
        cin >> n;
        s.push(n);
    }

    display(s);
    return 0;
}