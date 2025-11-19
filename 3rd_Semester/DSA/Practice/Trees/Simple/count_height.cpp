#include <iostream>
#include "queue.h"
using namespace std;

class Tree
{
private:
    Node *root;

public:
    void create_tree();
    void pre_order() { pre_order(root); }
    void pre_order(Node *p);
    int count_nodes() { return count_nodes(root); }
    int count_nodes(Node *p);
    int count_height() { return count_height(root); }
    int count_height(Node *p);
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

int Tree::count_nodes(Node *p)
{
    if (p)
    {
        return count_nodes(p->l_child) + count_nodes(p->r_child) + 1;
    }
    else
    {
        return 0;
    }
}

// int Tree::count_nodes(Node *p)
// {
//      int x,y;
//     if (p)
//     {
//        x=count_nodes(p->l_child);
//        y=count_nodes(p->r_child);
//        return x+y+1;
//     }
//     return 0;
//
// }

int Tree::count_height(Node *p)
{
    int x = 0, y = 0;

    if (p == 0)
        return 0;
    x = count_height(p->l_child);
    y = count_height(p->r_child);

    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

void Tree::pre_order(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        pre_order(p->l_child);
        pre_order(p->r_child);
    }
}
int main()
{
    Tree t;
    t.create_tree();
    t.pre_order();
    cout << endl;
    cout << t.count_nodes() << endl;
    cout << t.count_height() << endl;

    return 0;
}