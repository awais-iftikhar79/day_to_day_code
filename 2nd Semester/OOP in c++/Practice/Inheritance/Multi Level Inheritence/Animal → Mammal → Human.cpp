#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    void eat()
    {
        cout << "This Animal eats food" << endl;
    }
};
class Mamal : public Animal
{
public:
    void mamal()
    {
        cout << "Mamals breathe oxygen" << endl;
    }
};
class Human : public Mamal
{
public:
    void speak()
    {
        cout << "Human can speak" << endl;
    }
};
int main()
{

    Human h1;
    h1.eat();
    h1.mamal();
    h1.speak();

    return 0;
}