#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements at index " << i << endl;
        cin >> arr[i];
    }
    cout << "Orginal arrray : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int sum_even = 0, sum_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum_even += arr[i];
        }
        else
        {
            sum_odd += arr[i];
        }
    }
    cout << endl;
    cout << "Sum of even numbers : " << sum_even << endl;
    cout << "Sum of odd numbers : " << sum_odd << endl;
    
    delete[] arr;
    return 0;
}