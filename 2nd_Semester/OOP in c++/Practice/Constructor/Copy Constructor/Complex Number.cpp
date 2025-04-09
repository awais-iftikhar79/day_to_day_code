#include <iostream>
#include <string>
using namespace std;

class Complex
{
private:
    float real;
    float img;

public:
    Complex() {}
    Complex(float, float);
    Complex(Complex &obj)
    {
        real = obj.real;
        img = obj.img;
        cout << "Copy Constructor is calling " << endl;
    }
    void display()
    {
        cout << "Your Complex number is : " << real << " + " << img << "i" << endl;
    }
};
Complex ::Complex(float r, float i)
{
    real = r;
    img = i;
}
int main()
{
    Complex c1(2, 4.5);
    c1.display();
    Complex c2 = c1;
    c2.display();

    return 0;
}