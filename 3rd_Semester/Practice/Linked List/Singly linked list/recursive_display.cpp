#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first;

void creation_of_nodes(int arr[], int size)
{
    Node *new_node, *last; // last is for connecting previous node to next one (last->next = new node)
    first = new Node;

    first[0].data = arr[0];
    first[0].next = nullptr;

    last = first;

    for (int i = 1; i < size; i++)
    {
        new_node = new Node;

        new_node->data = arr[i];
        new_node->next = nullptr;

        last->next = new_node;
        last = new_node; // updating last by moving it one step forward
    }
}
void recursive_display(struct Node *p)
{
    if (p == nullptr)
    {
        cout << "NULL" << endl;
        
        return;
    }
    cout << p->data << " -> ";   //if i flip this two lines than reverse of linked list is printed
    recursive_display(p->next);
}
int main()
{
    int A[] = {1, 3, 5, 7, 9};
    creation_of_nodes(A, 5);

    recursive_display(first);
    return 0;
}