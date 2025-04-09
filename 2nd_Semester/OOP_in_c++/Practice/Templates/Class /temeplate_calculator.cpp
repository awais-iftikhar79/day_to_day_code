#include <iostream>
using namespace std;
template <class T>
class Calculator
{
private:
    T num1;
    T num2;

public:
    Calculator(T a, T b)
    {
        num1 = a;
        num2 = b;
    }
    T add()
    {
        return num1 + num2;
    }
    T subtract()
    {
        return num1 - num2;
    }
    T multiply()
    {
        return num1 * num2;
    }
    T divide()
    {
        if (num2 == 0)
        {
            cout << "Division is not possibe " << endl;
            return -1;
        }
        return num1 / num2;
    }
};
int main()
{
    Calculator<int> c1(3, 4);
    cout << "Addition : " << c1.add() << endl;
    cout << "Subtraction : " << c1.subtract() << endl;
    cout << "Mutiplication : " << c1.multiply() << endl;
    cout << "Division : " << c1.divide() << endl;
    cout << "-----------------------" << endl;
    Calculator<float> c2(3.1415, 9.765);
    cout << "Addition : " << c2.add() << endl;
    cout << "Subtraction : " << c2.subtract() << endl;
    cout << "Mutiplication : " << c2.multiply() << endl;
    cout << "Division : " << c2.divide() << endl;
    cout << "-----------------------" << endl;
    Calculator<double> c3(5.6, 4.09);
    cout << "Addition : " << c3.add() << endl;
    cout << "Subtraction : " << c3.subtract() << endl;
    cout << "Mutiplication : " << c3.multiply() << endl;
    cout << "Division : " << c3.divide() << endl;

    return 0;
}