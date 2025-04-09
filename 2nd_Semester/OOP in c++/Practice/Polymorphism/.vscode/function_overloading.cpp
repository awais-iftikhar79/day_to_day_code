#include <iostream>
using namespace std;
class Calculator
{
public:
    void multipy(int a, int b)
    {
        cout << "Answer is : " << a * b << endl;
    }
    void multipy(double a, double b)
    {
        cout << "Answer is : " << a * b << endl;
    }
    void multipy(int a, int b, int c)
    {
        cout << "Answer is : " << a * b * c << endl;
    }
};
int main()
{
    Calculator c1, c2, c3;

    c1.multipy(3, 4);
    c2.multipy(3.5, 6.8);
    c3.multipy(3, 6, 9);

    return 0;
}