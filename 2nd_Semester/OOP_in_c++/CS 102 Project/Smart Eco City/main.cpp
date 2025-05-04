#include <iostream>
#include <string>
#include <stdexcept>
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
        while (true)
        {
            try
            {
                cout << "====== WELCOME TO SMART CITY SIMULATOR ======" << endl;
                main_menu();
                cout << "Please Enter your choice (1-8)" << endl;
                cin >> choice;
                cin.ignore();

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    throw invalid_argument("Invalid Input !. Please Enter a number ");
                }

                if (choice < 1 || choice > 8)
                {
                    throw out_of_range("Invalid Input !. Please Enter number in range (1-8)");
                }
                break;
            }
            catch (const exception &e)
            {
                cout << "Error : " << e.what() << endl;
            }
        }

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Building name " << endl;
            getline(cin, name);

            while (true)
            {
                try
                {
                    building_menu();
                    cout << "Enter your choice (1-3)" << endl;
                    cin >> type;
                    cin.ignore();

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Input !. Please Enter a number ");
                    }

                    if (type < 1 || type > 3)
                    {
                        throw out_of_range("Invalid Input !. Building must be in range (1-3)");
                    }

                    break;
                }

                catch (const exception &e)
                {
                    cout << "Error : " << e.what() << endl;
                }
            }

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