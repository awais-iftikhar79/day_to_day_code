#include <iostream>
#include "queue.h"
using namespace std;

class Tree
{
private:
    Node *root;

public:
    void create_tree();
    void level_order() { level_order(root); };
    void level_order(Node *p);
};

void Tree::create_tree()
{
    Node *p, *t;
    int x;
    Queue q(20);

    cout << "Enter root value of tree " << endl;
    cin >> x;

    root = new Node;
    root->data = x;
    root->l_child = root->r_child = nullptr;

    q.enqueue(root);

    while (!q.is_empty())
    {
        p = q.dequeue();

        cout << "Enter left child of " << p->data << endl;
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->l_child = t->r_child = nullptr;
            p->l_child = t;
            q.enqueue(t);
        }

        cout << "Enter right child of " << p->data << endl;
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->l_child = t->r_child = nullptr;
            p->r_child = t;
            q.enqueue(t);
        }
    }
}
void Tree::level_order(Node *p)
{
    Queue q(20);
    cout << p->data << " ";
    q.enqueue(p);

    while (!q.is_empty())
    {
        p = q.dequeue();
        if (p->l_child)
        {
            cout << p->l_child->data << " ";
            q.enqueue(p->l_child);
        }
        if (p->r_child)
        {
            cout << p->r_child->data << " ";
            q.enqueue(p->r_child);
        }
    }
}
int main()
{
    Tree t;
    t.create_tree();
    t.level_order();
    return 0;
}