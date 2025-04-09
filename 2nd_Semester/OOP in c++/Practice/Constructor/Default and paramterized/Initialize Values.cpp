#include <iostream>
using namespace std;

class Rectangle
{
private:
    float lenghth, width;

public:
    Rectangle(int, int);
    float cal_area()
    {
        return lenghth * width;
    }
};
Rectangle ::Rectangle(int l, int w)
{
    lenghth = l;
    width = w;
    cout<<"Parameterized Constructor is called :"<<endl;
}
int main()
{
    float lenght, width;
    cout << "Enter length of rectangle" << endl;
    cin >> lenght;
    cout << "Enter width of rectangle" << endl;
    cin >> width;
    Rectangle rect(lenght, width);
    cout << "Area of rectangle is : " << rect.cal_area() << endl;
    return 0;
}