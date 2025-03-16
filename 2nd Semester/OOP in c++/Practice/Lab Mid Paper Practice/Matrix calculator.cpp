#include <iostream>
#include <string>
using namespace std;
void display_menu()
{
    cout << "------ WELCOME TO MTRIX SOLVER ------" << endl
         << "1.Read a Matrix from user input" << endl
         << "2.Perform Matrix Addition" << endl
         << "3.Perform Matrix Subtraction" << endl
         << "4.Perform Matrix Multiplication" << endl
         << "5.Transpose of a Matrix" << endl
         << "6.Identity Matrix Checker" << endl
         << "7.Display Matrix" << endl
         << "8.Exit" << endl
         << "---------------------------------------" << endl;
}
class Matrix
{
private:
    int row, col;
    double **data;

public:
    Matrix() {}
    Matrix(int r, int c) : row(r), col(c)
    {
        data = new double *[row];
        for (int i = 0; i < row; i++)
        {
            data[i] = new double[col];
        }
    }
    void read_matrix()
    {
        cout << "Enter elements of matrix " << row << " x " << col << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter element at index (" << i << "," << j << ")" << endl;
                cin >> data[i][j];
            }
        }
    }
    Matrix add_matrix(Matrix &other)
    {
        if (row != other.row || col != other.col)
        {
            cout << "Unable to add Matrices due to mismatch in dimentions" << endl;
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix subtract_matrix(Matrix &other)
    {
        if (row != other.row && col != other.col)
        {
            cout << "Unable to subtract Matrices due to mismatch in dimentions" << endl;
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix multiplication(Matrix &other)
    {
        if (col != other.row)
        {
            cout << "Multiplication is not possible " << endl;
            return Matrix(0, 0);
        }
        Matrix result(row, other.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    Matrix transpose()
    {
        Matrix result(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }
    bool is_identity()
    {
        if (row != col)
        {

            return false;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == j && data[i][j] != 1)
                {
                    return false;
                }
                else if (i != j && data[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void display_matrix()
    {
        cout << "------ DISPLAYING MATRIX ------" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{

    int row, col, choice;
    cout << "Enter number of rows" << endl;
    cin >> row;
    cout << "Enter number of columns" << endl;
    cin >> col;
    Matrix matrix(row, col);

    while (true)
    {
        display_menu();
        cout << "Please enter your choice " << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            matrix.read_matrix();
            matrix.display_matrix();
            break;
        }
        case 2:
        {
            int other_row, other_col;
            cout << "Enter number of rows of 2nd matrix" << endl;
            cin >> other_row;
            cout << "Enter number of coloumn of 2nd matrix" << endl;
            cin >> other_col;
            Matrix other(other_row, other_col);
            other.read_matrix();
            Matrix result = matrix.add_matrix(other);
            result.display_matrix();
            break;
        }
        case 3:
        {
            int other_row, other_col;
            cout << "Enter number of rows of 2nd matrix" << endl;
            cin >> other_row;
            cout << "Enter number of coloumn of 2nd matrix" << endl;
            cin >> other_col;
            Matrix other(other_row, other_col);
            other.read_matrix();
            Matrix result = matrix.subtract_matrix(other);
            result.display_matrix();
            break;
        };

        case 4:
        {
            int other_row, other_col;
            cout << "Enter number of rows of 2nd matrix" << endl;
            cin >> other_row;
            cout << "Enter number of coloumn of 2nd matrix" << endl;
            cin >> other_col;
            Matrix other(other_row, other_col);
            other.read_matrix();
            Matrix result = matrix.multiplication(other);
            result.display_matrix();

            break;
        }
        case 5:
        {
            Matrix result = matrix.transpose();
            result.display_matrix();
            break;
        }
        case 6:
        {
            bool identity = matrix.is_identity();
            if (identity)
            {
                cout << "Matrix is identity" << endl;
            }
            else
            {
                cout << "Matrix is not identity" << endl;
            }
            break;
        }

        case 7:
        {
            matrix.display_matrix();
            break;
        }
        case 8:
        {
            cout << "Exiting the progrma .... " << endl;
            exit(0);
            break;
        }
        default:
            break;
        }
    }

    return 0;
}