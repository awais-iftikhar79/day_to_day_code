#include <iostream>
#include <string>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(int, int);
    void dispaly()
    {
        cout << "Distance is : " << feet << " feet " << inches << " inches" << endl;
    }
    Distance operator+(Distance obj)
    {
        Distance temp;
        int total_inches = feet * 12 + inches + obj.feet * 12 + obj.inches;
        temp.feet = total_inches / 12;
        temp.inches = total_inches % 12;
        return temp;
    }
};
Distance::Distance(int f, int i)
{
    feet = f;
    inches = i;
}
int main()
{
    Distance d1(1, 11);
    Distance d2(2, 2);
    Distance d3 = d1 + d2;
    d3.dispaly();

    return 0;
}