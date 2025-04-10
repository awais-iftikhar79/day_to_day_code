#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
void display(vector<T> v)
{
    cout << "Strings in Vector are : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> v;
    string n;

    cout << "Enter a string" << endl;
    getline(cin, n);
    // v.push_back(n);  --> here i am not creating a vector
    // display(v);
    cout << n << endl;

    // auto count_a = 0;
    //  for (const auto &str : v)
    //  {
    //      count_a += count(str.begin(), str.end(), 'a'); // Count 'a' in each string
    //  }
    auto count_a = count(n.begin(), n.end(), 'a'); //--> this is for single string
    cout << "Target in string is " << count_a << " times" << endl;

    return 0;
}