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
    int count_leaf() { return count_leaf(root); }
    int count_leaf(Node *p);
    int count_deg_2() { return count_deg_2(root); }
    int count_deg_2(Node *p);
    int count_deg_1_2() { return count_deg_1_2(root); }
    int count_deg_1_2(Node *p);
    int count_deg_1() { return count_deg_1(root); }
    int count_deg_1(Node *p);
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

int Tree::count_leaf(Node *p)
{
    int x, y;
    if (p)
    {
        x = count_leaf(p->l_child);
        y = count_leaf(p->r_child);

        if (p->l_child == nullptr && p->r_child == nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::count_deg_2(Node *p)
{
    int x, y;
    if (p)
    {
        x = count_deg_2(p->l_child);
        y = count_deg_2(p->r_child);

        if (p->l_child != nullptr && p->r_child != nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::count_deg_1_2(Node *p)
{
    int x, y;
    if (p)
    {
        x = count_deg_1_2(p->l_child);
        y = count_deg_1_2(p->r_child);

        if (p->l_child != nullptr || p->r_child != nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::count_deg_1(Node *p)
{
    int x, y;
    if (p)
    {
        x = count_deg_1(p->l_child);
        y = count_deg_1(p->r_child);

        if (p->l_child != nullptr ^ p->r_child != nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
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
    cout << "Leaf Nodes : " << t.count_leaf() << endl;
    cout << "Degree 2 Nodes : " << t.count_deg_2() << endl;
    cout << "Degree 1,2 Nodes : " << t.count_deg_1_2() << endl;
    cout << "Degree 1 Nodes : " << t.count_deg_1() << endl;

    return 0;
}