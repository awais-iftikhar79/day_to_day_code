#include <iostream>
using namespace std;

struct UniverseCoordinate
{
    int s_num;
    int x_pos;
    int y_pos;
    bool is_snake;
};

void expand_array(struct UniverseCoordinate **&uc, int &r, int &c)
{
    int nr = r * 2;
    int nc = c * 2;

    UniverseCoordinate **new_array = new UniverseCoordinate *[nr];
    for (int i = 0; i < nr; i++)
    {
        new_array[i] = new UniverseCoordinate[nc];
    }
    // copiyng data form previouis array to new array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            new_array[i][j] = uc[i][j];
        }
    }
    // deleting previous array
    for (int i = 0; i < r; i++)
    {
        delete[] uc[i];
    }
    delete[] uc;

    uc = new_array;

    r = nr;
    c = nc;
}

void display(struct UniverseCoordinate **uc, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (uc[i][j].is_snake)
            {
                cout << uc[i][j].s_num<<" -> : Yes ";
            }
            else
            {
                cout << uc[i][j].s_num<<" -> : ---- ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int rows = 2, col = 2;
    int snake_count = 0;
    char choice;

    UniverseCoordinate **UC = new UniverseCoordinate *[rows];
    for (int i = 0; i < rows; i++)
    {
        UC[i] = new UniverseCoordinate[col];
    }

    do
    {
        int x, y;
        bool isSnake;

        cout << "Enter x-position " << endl;
        cin >> x;
        cout << "Enter y-position " << endl;
        cin >> y;
        cout << "Is there any sanke at this position? (1-Yes, 0-No)" << endl;
        cin >> isSnake;
        cin.ignore();

        if (x >= rows || y >= col)
        {
            expand_array(UC, rows, col);
            cout << "Array Expanded to " << rows << " x " << col << " size" << endl;
        }

        if (isSnake)
        {
            snake_count++;
        }
        

        UC[x][y].x_pos = x;
        UC[x][y].y_pos = y;
        UC[x][y].is_snake = isSnake;
        UC[x][y].s_num = (isSnake ? snake_count : '0');

        cout << "Do you want to add more coordinates" << endl;
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "------------- Snake Universe -----------" << endl
         << endl;
    display(UC, rows, col);

    return 0;
}