#include <iostream>
#include <string>
using namespace std;

class Num2;

class Num1
{
private:
    int num1;
    friend void compare_num(Num1, Num2);

public:
    Num1(int a)
    {
        num1 = a;
    }
};
class Num2
{
private:
    int num2;
    friend void compare_num(Num1, Num2);

public:
    Num2(int b)
    {
        num2 = b;
    }
};
void compare_num(Num1 obj1, Num2 obj2)
{
    if (obj1.num1 > obj2.num2)
    {
        cout << "The number in 1st class is greater : " << obj1.num1 << endl;
    }
    else
    {
        cout << "The number of 2nd class is greater : " << obj2.num2 << endl;
    }
}
int main()
{
    Num1 n1(5);
    Num2 n2(7);
    compare_num(n1, n2);
    return 0;
}