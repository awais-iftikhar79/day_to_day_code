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
    vector<float> v;
    size_t n;
    float val;

    cout << "Enter size of vector" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << endl;
        cin >> val;
        v.push_back(val);
    }
    display(v);
    // inserting 99 at index 2
    v.insert(v.begin() + 2, 99);
    display(v);
    // erasing value ar index 4
    v.erase(v.begin() + 4);
    display(v);

    return 0;
}