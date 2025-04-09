#include <iostream>
using namespace std;

void multiplication(int **m1, int **m2, int **r, int r1, int r2, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            r[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
void print(int **res, int r, int c)
{
    cout << "The result of Matrix 1 X Matrix 2 is : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int row1, row2, col1, col2;
    cout << "Enter number of rows of first matrix" << endl;
    cin >> row1;
    cout << "Enter number of coloumn of first matrix" << endl;
    cin >> col1;
    cout << "Enter number of rows of second matrix" << endl;
    cin >> row2;
    cout << "Enter number of coloumn of second matrix" << endl;
    cin >> col2;

    if (col1 != row2)
    {
        cout << "Multiplication is not possilbe because order of matrices are not matched " << endl;
        return -1;
    }

    int **matrix1 = new int *[row1];
    int **matrix2 = new int *[row2];
    int **result = new int *[row1];

    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = new int[col1];
    }
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = new int[col2];
    }
    for (int i = 0; i < row1; i++)
    {
        result[i] = new int[col2];
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter element at index [" << i << "][" << j << "]" << "of 1st matrix " << endl;
            cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "Enter element at index [" << i << "][" << j << "]" << "of 2nd matrix " << endl;
            cin >> matrix2[i][j];
        }
    }

    multiplication(matrix1, matrix2, result, row1, row2, col1, col2);
    print(result, row1, col2);

    for (int i = 0; i < row1; i++)
    {
        delete[] matrix1[i];
    }
    for (int i = 0; i < row2; i++)
    {
        delete[] matrix2[i];
    }
    for (int i = 0; i < row1; i++)
    {
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
    return 0;
}