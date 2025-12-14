#include <iostream>
using namespace std;

int find_max(int A[], int size)
{
    int max = A[0];

    for (int i = 1; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

void count_sort(int A[], int size)
{
    int max = find_max(A, size);

    int *C = new int[max + 1]; // creating dynamic array

    for (int i = 0; i < max + 1; i++)
    {
        C[i] = 0; // initializing array to zero
    }

    for (int i = 0; i < size; i++)
    {
        C[A[i]]++; // value of A = index of C
    }

    int i = 0, j = 0; // i for Array A and j is for Array C

    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
        {
            j++;
        }
    }
}
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int A[] = {3, 2, 8, 5, 2, 1, 5, 4, 2};
    count_sort(A, 9);
    display(A, 9);
    return 0;
}