#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array
{
private:
    T *arr;
    size_t size;

public:
    Array() {}
    Array(size_t s)
    {
        size = s;
        arr = new T[size];
    }
    void enter_data()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter Element at index " << i << endl;
            cin >> arr[i];
        }
    }
    void display()
    {
        cout << "Data entered in array is : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void find_max()
    {
        T greater = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > greater)
            {
                greater = arr[i];
            }
        }
        cout << "Max element in this array is : " << greater << endl;
    }
    T sum()
    {
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
    ~Array()
    {
        delete[] arr;
    }
};
int main()
{

    Array<int> a1(5);
    a1.enter_data();
    a1.display();
    a1.find_max();
    cout << "Sum of all enteries is : " << a1.sum() << endl;

    return 0;
}