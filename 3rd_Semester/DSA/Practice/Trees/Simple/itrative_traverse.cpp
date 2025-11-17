#include <iostream>
#include "stack.h"

using namespace std;

class Tree
{
private:
    Node *root;

public:
    void create_tree();
    void ipre_order() { ipre_order(root); }
    void ipre_order(Node *p);
    void iin_order() { iin_order(root); }
    void iin_order(Node *p);
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

void Tree::ipre_order(Node *p)
{
    Stack st(20);

    while (p || !st.is_empty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);
            p = (p->l_child);
        }
        else
        {
            p = st.pop();
            p = (p->r_child);
        }
    }
}

void Tree::iin_order(Node *p)
{
    Stack st(20);

    while (p || !st.is_empty())
    {
        if (p)
        {
            st.push(p);
            p = (p->l_child);
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = (p->r_child);
        }
    }
}
int main()
{
    Tree t;
    t.create_tree();
    cout << "Pre Order :";
    t.ipre_order();
    cout << endl
         << "In Order :";
    t.iin_order();

    return 0;
}