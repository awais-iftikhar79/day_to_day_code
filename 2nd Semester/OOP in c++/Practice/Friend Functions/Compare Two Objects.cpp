#include <iostream>
#include <string>
using namespace std;

class Box
{
private:
    float width, length;
    friend void compare_box(Box, Box);

public:
    Box(float, float);
};
Box ::Box(float w, float l)
{
    length = l;
    width = w;
}
void compare_box(Box obj1, Box obj2)
{
    float area1 = obj1.length * obj1.width;
    float area2 = obj2.length * obj2.width;
    if (area1 > area2)
    {
        cout << "After comparing , 1st object has greater Area : " << area1 << " square unit" << endl;
    }
    else
    {
        cout << "After comparing , 2nd object has greater Area : " << area2 << " square unit" << endl;
    }
}
int main()
{
    Box b1(1, 10);
    Box b2(1, 20);
    compare_box(b1, b2);
    
    return 0;
}