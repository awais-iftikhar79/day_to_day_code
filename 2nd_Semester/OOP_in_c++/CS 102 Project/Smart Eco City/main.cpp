#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "City_Simulator.h"

void main_menu()
{
    cout << "\t\033[1;36m1.Add Building" << endl
         << "\t2.Add Transport" << endl
         << "\t3.Add Utility" << endl
         << "\t4.Perform Eco Activity" << endl
         << "\t5.Add Citizen" << endl
         << "\t6.View Pollution Report" << endl
         << "\t7.View Eco Points" << endl
         << "\t8.Exit \033[0m" << endl; // Bright Cyan
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
                cout << "\033[1;33m ====== WELCOME TO SMART CITY SIMULATOR ======\033[0m" << endl; // Bright Yellow
                main_menu();
                cout << "\033[0;37mPlease Enter your choice (1-8)\033[0m" << endl; // white
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
                cout << "\033[1;31mError : " << e.what() << " \033[0m" << endl; //  Bright Red
            }
        }

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Name of Building " << endl;
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
                        throw out_of_range("Invalid Input !. Building type must be in range (1-3)");
                    }

                    break;
                }

                catch (const exception &e)
                {
                    cout << "\033[1;31mError : " << e.what() << " \033[0m" << endl; //  Bright Red
                }
            }

            simulator.add_building(name, type);
        }
        break;
        case 2:
        {
            cout << "Enter Name of Vehicle " << endl;
            getline(cin, name);

            while (true)
            {
                try
                {
                    transport_menu();
                    cout << "Enter your choice  (1-2)" << endl;
                    cin >> type;
                    cin.ignore();

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Input !. Please Enter number");
                    }

                    if (type < 1 || type > 2)
                    {
                        throw out_of_range("Invalid Input !. Transport type must be in range (1-2)");
                    }

                    break;
                }

                catch (const exception &e)
                {
                    cout << "\033[1;31mError : " << e.what() << " \033[0m" << endl; //  Bright Red
                }
            }

            simulator.add_transport(name, type);
        }
        break;
        case 3:
        {
            cout << "Enter Utility Name : " << endl;
            getline(cin, name);

            while (true)
            {
                try
                {
                    utility_menu();
                    cout << "Enter your choice  (1-3)" << endl;
                    cin >> type;
                    cin.ignore();

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Input !. Please Enter number ");
                    }

                    if (type < 1 || type > 3)
                    {
                        throw out_of_range("Invalid Input !. Utilty type must be in range of (1-3)");
                    }
                    break;
                }

                catch (const exception &e)
                {
                    cout << "\033[1;31mError : " << e.what() << " \033[0m" << endl; //  Bright Red
                }
            }

            simulator.add_utility(name, type);
        }
        break;
        case 4:
        {
            cout << "Enter Name : " << endl;
            getline(cin, name);

            while (true)
            {
                try
                {
                    eco_activity_menu();
                    cout << "Enter your choice : " << endl;
                    cin >> type;
                    cin.ignore();

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Inputs !. Please Enter a number ");
                    }

                    if (type < 1 || type > 2)
                    {
                        throw out_of_range("Invalid Input !. Eco-Activity must be in range of (1-2)");
                    }

                    break;
                }
                catch (const exception &e)
                {
                    cout << "\033[1;31m  Error : " << e.what() << "\033[0m" << endl;
                }
            }

            simulator.add_eco_activity(name, type);
        }
        break;
        case 5:
        {
            bool mode;

            cout << "Enter Name of Citizen " << endl;
            getline(cin, name);

            while (true)
            {
                try
                {
                    citizen_transport_mode();
                    cout << "Enter your choice" << endl;
                    cin >> type;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Input !. Please Enter a number");
                    }

                    if (type < 1 || type > 3)
                    {
                        throw out_of_range("Invalid Input !. Transport Mode must be in range (1-3)");
                    }

                    break;
                }

                catch (const exception &e)
                {
                    cout << "\033[1;31m  Error : " << e.what() << "\033[0m" << endl;
                }
            }

            while (true)
            {
                try
                {
                    citizen_recycle_menu();
                    cout << "Enter your choice " << endl;
                    cin >> mode;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Invalid Input !. Please Enter a number");
                    }

                    if (type < 1 || type > 3)
                    {
                        throw out_of_range("Invalid Input !. Transport Mode must be in range (1-3)");
                    }

                    break;
                }

                catch (const exception &e)
                {
                    cout << "\033[1;31m  Error : " << e.what() << "\033[0m" << endl;
                }
            }

            simulator.add_citizen(name, type, mode);

            break;
        }

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
            exit(0);
        }
        break;

        default:
            cout << "Invalide Option.Select (1-8)" << endl;
            break;
        }
    }

    return 0;
}