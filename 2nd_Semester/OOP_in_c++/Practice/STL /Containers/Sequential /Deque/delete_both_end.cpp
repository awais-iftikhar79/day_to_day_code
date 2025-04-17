#include <iostream>
#include <deque>
using namespace std;

template <typename T>
void display(deque<T> d)
{
    cout << "Entities in Deque are : ";
    for (T val : d)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d;
    size_t n;
    int val;

    cout << "Enter size of Deque " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << endl;
        cin >> val;
        d.push_front(val);
    }

    display(d);

    cout << "After deleting element from both ends " << endl;
    d.pop_front();
    d.pop_back();

    display(d);
    
    return 0;
}