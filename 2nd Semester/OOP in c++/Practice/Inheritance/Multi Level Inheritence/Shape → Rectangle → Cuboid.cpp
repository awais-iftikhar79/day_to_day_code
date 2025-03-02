#include <iostream>
#include <string>
using namespace std;
class Shape
{
public:
    void display_shape()
    {
        cout << "This is a shape" << endl;
    }
};
class Rectangle : public Shape
{
private:
    float length, width;

public:
    void set_rectangle(float, float);

    void display_area()
    {
        double area = length * width;
        cout << "Area of rectangle is : " << area << " sqaure unit" << endl;
    }
    double getArea()
    {
        return length * width;
    }
};
void Rectangle ::set_rectangle(float l, float w)
{
    width = w;
    length = l;
}
class Cuboid : public Rectangle
{
private:
    float height;

public:
    void set_cuboid(float);
    void display_volume()
    {
        cout << "Volume of Cuboid is : " << getArea() * height << " cubic unit" << endl;
    }
};
void Cuboid ::set_cuboid(float h)
{
    height = h;
}
int main()
{

    Cuboid c1;
    c1.set_rectangle(2.4, 5.6);
    c1.set_cuboid(5.9);
    c1.display_shape();
    c1.display_area();
    c1.display_volume();

    return 0;
}