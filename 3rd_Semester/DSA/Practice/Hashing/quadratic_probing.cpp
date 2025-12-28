#include <iostream>
using namespace std;

#define SIZE 10

// Hash function
int hash_index(int key)
{
    return key % SIZE;
}

// Quadratic probing to find next empty slot
int quad_probe(int H[], int key)
{
    int index = hash_index(key);
    int i = 0;

    // Keep probing until empty slot is found
    while (H[(index + i * i) % SIZE] != 0)
    {
        i++;
        if (i == SIZE)
        { // table full
            cout << "Hash table overflow!" << endl;
            return -1;
        }
    }

    return (index + i * i) % SIZE;
}

// Insert key using quadratic probing
void insert(int H[], int key)
{
    int index = hash_index(key);

    if (H[index] != 0)
    {
        index = quad_probe(H, key);
        if (index == -1)
            return; // table full
    }

    H[index] = key;
}

// Display hash table
void display(int H[])
{
    cout << "Index -> Value" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> " << H[i] << endl;
    }
}

// Search key using quadratic probing
int search(int H[], int key)
{
    int index = hash_index(key);
    int i = 0;

    while (H[(index + i * i) % SIZE] != 0)
    {
        if (H[(index + i * i) % SIZE] == key)
            return (index + i * i) % SIZE;
        i++;
        if (i == SIZE)
            break; // key not found
    }

    return -1; // key not found
}

int main()
{
    int H[SIZE] = {0};

    // Insert keys
    insert(H, 23);
    insert(H, 43);
    insert(H, 13);
    insert(H, 27);
    insert(H, 56);

    display(H);

    // Search key
    int key = 27;
    int result = search(H, key);
    if (result != -1)
        cout << "Key " << key << " found at index " << result << endl;
    else
        cout << "Key " << key << " not found." << endl;

    return 0;
}
