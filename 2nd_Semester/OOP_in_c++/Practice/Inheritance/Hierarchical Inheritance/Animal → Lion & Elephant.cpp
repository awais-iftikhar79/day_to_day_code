#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    void eat()
    {
        cout << "Animal is eating" << endl;
    }
};
class Lion : public Animal
{
public:
    void roar()
    {
        cout << "Lion is roaring" << endl;
    }
};
class Elephant : public Animal
{
public:
    void trumpet()
    {
        cout << "Elephant is trumpting" << endl;
    }
};
int main()
{
    Lion l;
    Elephant e;
    cout << "------Lion------" << endl;
    l.eat();
    l.roar();
    cout << "------Elephant------" << endl;
    e.eat();
    e.trumpet();
    return 0;
}