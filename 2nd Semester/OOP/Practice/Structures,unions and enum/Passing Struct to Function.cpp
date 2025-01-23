#include <iostream>
using namespace std;

struct Rectangle
{

    float length, width;
};

float cal_area(Rectangle r)
{

    return r.length * r.width;
}

int main()
{
    Rectangle rect;
    cout << "Enter lenght of rectangle " << endl;
    cin >> rect.length;
    cout << "Enter width of rectangle" << endl;
    cin >> rect.width;
    float area = cal_area(rect);
    cout << "Area of rectangle is : " << area << endl;
    return 0;
}