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

int main()
{
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};
    
    display(&arr);

    return 0;
}