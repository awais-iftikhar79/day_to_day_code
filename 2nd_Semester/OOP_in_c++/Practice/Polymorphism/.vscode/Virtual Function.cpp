#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    virtual void make_sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};
class Dog : public Animal
{
public:
    void make_sound()
    {
        cout << "Dog Barks" << endl;
    }
};
class Cat : public Animal
{
public:
    void make_sound()
    {
        cout << "Cat meows" << endl;
    }
};
int main()
{
    Animal *ptr;

    Dog d;
    Cat c;

    ptr = &d;
    ptr->make_sound();

    ptr = &c;
    ptr->make_sound();

    return 0;
}