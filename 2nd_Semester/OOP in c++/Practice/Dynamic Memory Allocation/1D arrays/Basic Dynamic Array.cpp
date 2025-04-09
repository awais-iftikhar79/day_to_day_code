#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of an array" << endl;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << endl;
        cin >> arr[i];
    }

    cout << "Original array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Reverse of this array is : ";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}