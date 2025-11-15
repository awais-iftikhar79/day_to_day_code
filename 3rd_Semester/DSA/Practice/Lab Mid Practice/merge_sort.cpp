#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;

    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }

    for (; j <= h; j++)
    {
        B[k++] = A[j];
    }

    for (int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void recursive_merge(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        int mid = (l + h) / 2;

        recursive_merge(A, l, mid);
        recursive_merge(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int A[] = {11, 13, 17, 7, 12, 16, 9, 24, 3, 10};
    display(A, 10);
    recursive_merge(A, 0, 9);
    display(A, 10);

    return 0;
}