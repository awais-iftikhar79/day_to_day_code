#include <iostream>
#include <string>
using namespace std;
class Shape
{
public:
    virtual void area()
    {
        cout << "Area formula not defined" << endl;
    }
};
class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(int a, int b) : length(a), width(b) {}
    void area()
    {
        cout << "Area od Rectangle is : " << length * width << endl;
    }
};
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(int r) : radius(r) {}
    void area()
    {
        cout << "Area of circle is : " << radius * radius * 3.1415 << endl;
    }
};
int main()
{
    Shape *shape1 = new Rectangle(3.4, 5.7);
    Shape *shape2 = new Circle(4.6);

    shape1->area();
    shape2->area();
    
    delete shape1;
    delete shape2;
    return 0;
}