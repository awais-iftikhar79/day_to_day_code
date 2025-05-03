#include <iostream>
#include <string>
using namespace std;

#include "City_Simulator.h"

void main_menu()
{
    cout << "1.Add Building" << endl
         << "2.Add Transport" << endl
         << "3.Add Utility" << endl
         << "4.Perform Eco Activity" << endl
         << "5.Add Citizen" << endl
         << "6.View Pollution Report" << endl
         << "7.View Eco Points" << endl
         << "8.Exit" << endl;
}

int main()
{
    City_Simulator simulator;
    int choice, type;
    string name;

    while (true)
    {
        cout << "====== WELCOME TO SMART CITY SIMULATOR ======" << endl;
        main_menu();
        cout << "Please Enter your choice (1-8)" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Building name " << endl;
            getline(cin, name);
            building_menu();
            cout << "Enter your choice (1-3)" << endl;
            cin >> type;
            cin.ignore();
            simulator.add_building(name, type);
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
        }
        break;
        case 6:
        {
        }
        break;
        case 7:
        {
        }
        break;

        case 8:
        {
        }
        break;

        default:
            cout << "Invalide Option.Select (1-8)" << endl;
            break;
        }
    }

    return 0;
}