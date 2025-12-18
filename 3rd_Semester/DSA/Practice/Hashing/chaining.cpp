#include <iostream>
#include "linked_list.h"
using namespace std;

#define SIZE 10

class Hash_map
{
private:
    Linked_List HT[SIZE];

    int find_index(int key) { return key % 10; }

public:
    Hash_map()
    {
    }

    void insert(int key)
    {
        int index = find_index(key);

        HT[index].insert_at_head(key);
    }

    Node *search(int key)
    {
        int index = find_index(key);

        return HT[index].Lsearch(key);
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";
            HT[i].display();
            cout << endl;
        }
    }
};
int main()
{
    Hash_map ht;

    ht.insert(10);
    ht.insert(11);
    ht.insert(12);
    ht.insert(22);
    ht.insert(27);

    ht.display();

    Node *result = ht.search(12);

    if (result)
    {
        cout << result->data << " found" << endl;
    }
    else
    {
        cout << result->data << "not found" << endl;
    }

    return 0;
}