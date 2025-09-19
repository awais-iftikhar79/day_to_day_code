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

int recursion_binary_search(struct Array arr, int low, int high, int key)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            return recursion_binary_search(arr, low, mid - 1, key);
        }
        else
        {
            return recursion_binary_search(arr, mid + 1, high, key);
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

    if (recursion_binary_search(arr, 0, arr.length - 1, target) != -1)
    {
        cout << "Key Present at index : " << recursion_binary_search(arr, 0, arr.length - 1, target) << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    display(&arr);

    return 0;
}