#include <iostream>
using namespace std;

int main()
{
    int row, col, row_sum = 0, col_sum = 0;
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
    cout << "Matrix is : \n\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        row_sum = 0;
        for (int j = 0; j < col; j++)
        {
            row_sum += matrix[i][j];
        }
        cout << "The sum of " << i + 1 << " row is : " << row_sum << endl;
    }

    for (int i = 0; i < col; i++)
    {
        col_sum = 0;
        for (int j = 0; j < row; j++)
        {
            col_sum += matrix[j][i];
        }
        cout << "The sum of " << i + 1 << " colloumn is : " << col_sum << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete matrix;

    return 0;
}