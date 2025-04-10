#include <iostream>
using namespace std;

template <typename T>
void swap_values(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 4, y = 5;
    cout << "x = " << x << " , y = " << y << endl;
    swap_values(x, y);
    cout << "After Swaping : " << endl;
    cout << "x = " << x << " , y = " << y << endl;

    cout << "---------------" << endl;
    
    float a = 3.14, b = 6.7;
    cout << "a = " << a << " , b = " << b << endl;
    swap_values(a, b);
    cout << "a = " << a << " , b = " << b << endl;

    return 0;
}