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

int linear_search(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(arr->A[i], arr->A[i - 1]);  //shifting value 1 index backward
            return (i-1); // for succesfull search
        }
    }
    return -1; // for unsuccesfull search
}

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};

    int target;
    cout << "Enter targeted value u wana search" << endl;
    cin >> target;

    display(&arr);
    if (linear_search(&arr, target) == -1)
    {
        cout << "Search was unsuccessful " << endl;
    }
    else
    {
        cout << "Target value is at index " << linear_search(&arr, target) << endl;
    }
    display(&arr);

    return 0;
}