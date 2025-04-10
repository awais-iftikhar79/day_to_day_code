#include <iostream>
using namespace std;

template <typename T>
void compare_values(T a, T b, T c)
{
    if (a > b && a > c)
    {
        cout << "Greater Number is : " << a << endl;
    }
    else if (b > a && b > c)
    {
        cout << "Greater Number is : " << b << endl;
    }
    else
    {
        cout << "Greater Number is : " << c << endl;
    }
}
int main()
{
    compare_values(4.3, 5.4, 6.7);

    return 0;
}