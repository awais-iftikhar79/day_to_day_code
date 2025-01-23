#include <iostream>
#include <string>
using namespace std;
struct Adress
{
    string city;
    string street;
    int postal_code;
};
struct Person
{
    string name;
    double age;
    Adress adress;
};

int main()
{
    Person p1;
    cout << "Enter your name" << endl;
    getline(cin, p1.name);
    cout << "Enter your age" << endl;
    cin >> p1.age;
    cin.ignore();
    cout << "Enter city name " << endl;
    getline(cin, p1.adress.city);
    cout << "Enter tour street" << endl;
    getline(cin, p1.adress.street);
    cout << "Enter your postal code" << endl;
    cin >> p1.adress.postal_code;

    cout << "\n--- Person Information ---" << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Street: " << p1.adress.street << endl;
    cout << "City: " << p1.adress.city << endl;
    cout << "Postal Code : " << p1.adress.postal_code << endl;

    return 0;
}