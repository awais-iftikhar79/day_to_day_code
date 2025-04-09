#include <iostream>
using namespace std;

int main()
{
    int rows, col;
    cout << "Enter number of rows " << endl;
    cin >> rows;
    cout << "enter number of coloumns " << endl;
    cin >> col;
    // creating space for input
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[col];
    }
    // iput data from user
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element at index [" << i << "][" << j << "] ";
            cin >> arr[i][j];
        }
    }
    cout << endl;
    // output
    cout<<"Original martix is : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout<<"Transpose of a matrix is : \n"; 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        delete arr[i];
    }
    delete arr;
    return 0;
}