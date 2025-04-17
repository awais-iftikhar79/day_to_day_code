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
    cout<<v.size()<<endl;
    
    for (vector<int>::iterator it = v.begin(); it != v.end();)
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }
    cout<<v.size()<<endl;
    display(v);

    return 0;
}