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
        cout << "Ente element at index " << i << endl;
        cin >> arr[i];
    }
    char choice;
    cout << "Do want to increase size of an array " << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        int new_size;
        cout << "Enter new size of an array " << endl;
        cin >> new_size;
        int *new_arr = new int[new_size];
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cout << "Enter  additiional  " << new_size - size << " elements" << endl;
        for (int i = size; i < new_size; i++)
        {
            cout << "Enter elements at index " << i << endl;
            cin >> arr[i];
        }
        size = new_size;
    }

    cout << "Final array is : [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;
    delete[] arr;
    return 0;
}