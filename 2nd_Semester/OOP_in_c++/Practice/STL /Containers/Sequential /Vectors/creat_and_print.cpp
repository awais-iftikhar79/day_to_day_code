#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display(vector<T> v)
{
    cout << "Elements in Vector ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v;
    int val;
    size_t n;
    cout << "Enter size of vector" << endl;
    cin >> n;
    // v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << endl;
        cin >> val;
        v.push_back(val);
    }
    display(v);

    return 0;
}