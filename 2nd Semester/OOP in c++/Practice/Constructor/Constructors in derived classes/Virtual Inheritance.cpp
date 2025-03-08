#include <iostream>
#include <string>
using namespace std;
class Animal
{
private:
    string species;

public:
    Animal(string s) : species(s)
    {
        cout << "Animal Constructor is calling" << endl;
    }
};
class Mamal : virtual public Animal
{
public:
    Mamal(string s) : Animal(s)
    {
        cout << "Mamal Constructor is calling" << endl;
    }
};
class Bird : virtual public Animal
{
public:
    Bird(string s) : Animal(s)
    {
        cout << "Bird Constructor is calling" << endl;
    }
};
class Bat : public Mamal, public Bird
{
public:
    Bat(string m, string b) : Animal(m), Mamal(m), Bird(b)
    {
        cout << "Bat Consructor is calling" << endl;
    }
};
int main()
{
    Bat b("Mamal Specie", "Bird Specie");
    return 0;
}
