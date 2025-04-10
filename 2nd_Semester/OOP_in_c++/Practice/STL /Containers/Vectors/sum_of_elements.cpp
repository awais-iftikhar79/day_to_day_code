#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T sum(vector<T> v)
{
    T sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
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

    float t_sum = sum(v);
    cout << "Sum of all elements is vector is : " << t_sum << endl;

    return 0;
}