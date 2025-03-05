#include <iostream>
#include <string>
#define PI 3.1415
using namespace std;
class Shape
{
public:
    void shape()
    {
        cout << "This is a shape" << endl;
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    void set_radius(double r)
    {
        radius = r;
    }
    double getArea()
    {
        return PI * radius * radius;
    }
    void display_cirlce()
    {
        cout << "------Circle------" << endl
             << "Radius : " << radius << endl
             << "Area : " << getArea() << endl;
    }
};
class Rectangle : public Shape
{
private:
    double length, width;

public:
    void set_dimensions(double l, double w)
    {
        length = l;
        width = w;
    }
    double get_react_area()
    {
        return length * width;
    }
    void display_rect()
    {
        cout << "------Rectangle------" << endl
             << "Length : " << length << endl
             << "Width : " << width << endl
             << "Area : " << get_react_area() << endl;
    }
};
int main()
{
    Circle c;
    Rectangle r;
    c.set_radius(3.14);
    c.display_cirlce();
    r.set_dimensions(4, 6.3);
    r.display_rect();
    return 0;
}