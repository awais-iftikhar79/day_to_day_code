#include <iostream>
using namespace std;

struct UniverseCoordinate
{
    int s_num;
    int x_pos;
    int y_pos;
    bool is_snake;
};

void display(struct UniverseCoordinate uc[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Snake ID : " << uc[i].s_num << endl;
        cout << "Coordinates (" << uc[i].x_pos << "," << uc[i].y_pos << ")" << endl;
        cout << "Is there any Snake : " << (uc[i].is_snake ? "Yes" : "No") << endl;
        cout << "---------------------------------" << endl;
    }
}

int main()
{
    UniverseCoordinate *univers = new UniverseCoordinate[5];

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter ID of " << i + 1 << " snake" << endl;
        cin >> univers[i].s_num;
        cout << "Enter x-position of sanke" << endl;
        cin >> univers[i].x_pos;
        cout << "Enter y-position of sanke" << endl;
        cin >> univers[i].y_pos;
        cout << "Is on (x,y) position there is snake (1-Yes, 0-No)" << endl;
        cin >> univers[i].is_snake;
    }
    
    display(univers, 2);

    delete[] univers;

    return 0;
}