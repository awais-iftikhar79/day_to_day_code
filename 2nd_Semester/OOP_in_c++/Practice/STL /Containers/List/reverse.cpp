#include <iostream>
#include <list>
using namespace std;

template <typename T>
void display(list<T> l)
{
    cout << "Entities in list are : ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l;
    int val;
    size_t n;

    cout << "Enter size of list " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << endl;
        cin >> val;
        l.push_back(val);
    }

    display(l);

    l.reverse();

    cout << "Reverse of list is : " << endl;
    display(l);

    return 0;
}