#include <iostream>
using namespace std;
#define SIZE 10

int hash_index(int key) { return key % 10; }

int probe(int H[], int key)
{
    int index = hash_index(key);

    int i = 0;
    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }

    return index + i;
}

void insert(int H[], int key)
{
    int index = hash_index(key);

    if (H[index] != 0)
    {
        index = probe(H, key);
    }

    H[index] = key;
}

void display(int H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> " << H[i];
        cout << endl;
    }
}

int search(int H[], int key)
{
    int index = hash_index(key);

    int i = 0;
    while (H[(index + i) % SIZE] != key)
    {
        i++;
    }

    return index + i;
}

int main()
{
    int H[SIZE] = {0};

    insert(H, 10);
    insert(H, 12);
    insert(H, 22);
    insert(H, 32);
    insert(H, 55);
    insert(H, 9);

    display(H);

    int result = search(H, 22);
    cout << H[result];
    return 0;
}