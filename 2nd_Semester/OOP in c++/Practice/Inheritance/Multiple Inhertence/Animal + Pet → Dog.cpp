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
class Pet
{
public:
    void play()
    {
        cout << "Pet is playing " << endl;
    }
};

class Dog : public Pet, public Animal
{
public:
    void bark()
    {
        cout << "Dog is barking" << endl;
    }
};
int main()
{

    Dog d;
    d.eat();
    d.play();
    d.bark();

    return 0;
}