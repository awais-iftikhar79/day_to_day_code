#ifndef POLLUTION_LEVEL
#define POLLUTION_LEVEL

#include <iostream>
#include <string>
using namespace std;

class Pollution_Level
{
private:
    int air_pollution = 0;
    int waste_level = 0;

public:
    void update_pollution(string type)
    {
        if (type == "Coal" || type == "Non-Electric Vehilce")
        {
            air_pollution += 10;
        }
        else if (type == "Commercial")
        {
            waste_level += 5;
        }
        else if (type == "Recycling" || type == "Tree Planting")
        {
            waste_level -= 5;
            air_pollution -= 5;
        }
        if (waste_level < 0)
            waste_level = 0;
        if (air_pollution < 0)
            air_pollution = 0;
    }
    void report()
    {
        cout << "Air Pollution Level : " << air_pollution << "/100" << endl;
        cout << "Waste  Level : " << waste_level << "/100" << endl;
    }
};

#endif