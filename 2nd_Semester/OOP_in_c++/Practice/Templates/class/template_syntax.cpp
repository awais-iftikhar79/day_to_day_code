#include <iostream>
using namespace std;

template <class T>
class Box
{
private:
    T weight;

public:
    Box(T w)
    {
        weight = w;
    }
    void display()
    {
        cout << "Box weight is : " << weight << endl;
    }
};
int main()
{
    Box<int> b1(30);
    Box<float> b2(45.74);
    Box<double> b3(36.55);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}