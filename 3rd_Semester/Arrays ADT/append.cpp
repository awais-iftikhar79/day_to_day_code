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

void append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = value;
        arr->length++;
    }
    else
    {
        cout << "Array is already full" << endl;
    }
}

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};
    
    int num;
    cout << "Enter number that you want to append" << endl;
    cin >> num;

    append(&arr, num);
    display(&arr);
    
    return 0;
}