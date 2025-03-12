#include <iostream>
#include <string>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex() {}
    Complex(int a, int b) : real(a), imag(b) {}
    Complex operator+(Complex &other)
    {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }
    void display()
    {
        cout << real << " + " << imag << " i" << endl;
    }
};
int main()
{
    Complex c1(1, 2);
    c1.display();
    Complex c2(3, 4);
    c2.display();
    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}