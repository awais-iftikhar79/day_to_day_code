#ifndef CITY_OBJECT_H
#define CITY_OBJECT_H

#include <string>
using namespace std;

class City_Object
{
protected:
    string name;

public:
    City_Object(string n) : name(n) {}
    virtual void operate() = 0;
};
#endif