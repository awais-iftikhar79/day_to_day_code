#include <iostream>
#include <string>
using namespace std;
#define PI 3.1415

class Circle
{
private:
    float radius;
    friend void cal_area(Circle);

public:
    Circle(float);
};
Circle ::Circle(float r)
{
    radius = r;
}
void cal_area(Circle r)
{
    float area = r.radius * r.radius * PI;
    cout << "Area of Circle is : " << area << " square unit" << endl;
}
int main()
{
    Circle c1(5.34);
    cal_area(c1);

    return 0;
}