#include <iostream>
using namespace std;
template <typename T>
T add(T a, T b)
{
    T sum ;
    sum = a + b;
    return sum;
}
int main()
{
    int a = 4, b = 7;
    cout << "Sum is : " << add(a, b) << endl;

    cout << "-----------------" << endl;

    string x = "Awais ", y = "Iftikhar";
    cout << "Sum is : " << add(x, y) << endl;

    return 0;
}