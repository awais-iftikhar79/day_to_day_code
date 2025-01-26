#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of an array " << endl;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter elemnet at index " << i << endl;
        cin >> arr[i];
    }
    cout << "Elements in your array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Max Entery in your array is : " << max << endl;
    delete[] arr;
    return 0;
}