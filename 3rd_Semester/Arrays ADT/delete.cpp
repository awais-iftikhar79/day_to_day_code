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

int Delete(struct Array *arr, int indx)
{
    int deleted_value, i;
    if (indx >= 0 && indx < arr->length)
    {
        deleted_value = arr->A[indx];
        for (i = indx; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
    }
    return deleted_value;
}

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};

    int index;
    cout << "Enter index at which u want to delete value" << endl;
    cin >> index;

    display(&arr);
    cout << "Deleted Value is : " << Delete(&arr, index) << endl;
    display(&arr);

    return 0;
}