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
    size_t n, index;
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

    cout << "Enter index of element you want to acess " << endl;
    cin >> index;

    cout << "Element at index " << index << " is : " << d.at(index) << endl;
    cout << "Element at front : " << d.front() << endl;
    cout << "Element at back : " << d.back() << endl;
    
    display(d);
    return 0;
}