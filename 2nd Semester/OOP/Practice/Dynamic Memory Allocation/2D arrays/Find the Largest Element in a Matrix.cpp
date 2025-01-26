#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter number of rows " << endl;
    cin >> row;
    cout << "Enter number of coloumns " << endl;
    cin >> col;

    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    cout << "Enter enteries of matrix\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element at index [" << i << "][" << j << "] ";
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix is : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int greater = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] > greater)
            {
                greater = matrix[i][j];
            }
        }
    }

    cout << "The greatest element in matrix is : " << greater << endl;

    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete matrix;

    return 0;
}