#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size = 10;
    int length = 5;
};

void display(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->A[i] << " ";
    }
    cout << endl;
};

void insert(struct Array *arr, int indx, int value)
{
    if (indx > 0 && indx < arr->length)
    {
        for (int i = arr->length; i > indx; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[indx] = value;
        arr->length++;
    }
}

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};

    int index, num;
    cout << "Enter number at which u want to put number" << endl;
    cin >> index;
    cout << "Enter number u want to insert" << endl;
    cin >> num;

    insert(&arr, index, num);
    display(&arr);

    return 0;
}