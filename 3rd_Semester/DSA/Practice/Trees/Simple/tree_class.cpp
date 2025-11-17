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
    void in_order() { in_order(root); }
    void in_order(Node *p);
    void post_order() { post_order(root); }
    void post_order(Node *p);
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

void Tree::pre_order(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        pre_order(p->l_child);
        pre_order(p->r_child);
    }
}

void Tree::in_order(Node *p)
{
    if (p)
    {
        in_order(p->l_child);
        cout << p->data << " ";
        in_order(p->r_child);
    }
}

void Tree::post_order(Node *p)
{
    if (p)
    {
        post_order(p->l_child);
        post_order(p->r_child);
        cout << p->data << " ";
    }
}
int main()
{
    Tree t;
    t.create_tree();
    cout << "Pre_order : ";
    t.pre_order();
    cout << endl
         << "Inorder : ";
    t.in_order();
    cout << endl
         << "Post_order : ";
    t.post_order();
    cout << endl;

    return 0;
}