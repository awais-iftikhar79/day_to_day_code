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

int binary_search(struct Array arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length - 1;
    

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};

    int target;
    cout << "Enter target number u want to find" << endl;
    cin >> target;
    cin.ignore();

    if (binary_search(arr, target) != -1)
    {
        cout << "Key Present at index : " << binary_search(arr, target) << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    display(&arr);

    return 0;
}