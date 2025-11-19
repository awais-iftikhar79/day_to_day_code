
#include <iostream>
#include "stack.h"

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

    void ipre_order() { ipre_order(root); }
    void ipre_order(Node *p);

    void iin_order() { iin_order(root); }
    void iin_order(Node *p);

    void level_order() { level_order(root); };
    void level_order(Node *p);

    int count_nodes() { return count_nodes(root); }
    int count_nodes(Node *p);

    int count_height() { return count_height(root); }
    int count_height(Node *p);

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
int main()
{
    Tree t;

    t.create_tree();
    cout << "============== DETAILS OF TREE ================" << endl
         << endl;

    cout << "Pre_order :    ";
    t.pre_order();
    cout << endl
         << "Inorder :  ";
    t.in_order();
    cout << endl
         << "Post_order :   ";
    t.post_order();
    cout << endl
         << "Level Order :  ";
    t.level_order();
    cout << endl
         << "Total Nodes :    " << t.count_nodes();
    cout << endl
         << "Height of Tree :   " << t.count_height();
    cout << endl;

    cout << "Leaf Nodes :   " << t.count_leaf() << endl;
    cout << "Degree 2 Nodes :   " << t.count_deg_2() << endl;
    cout << "Degree 1,2 Nodes :    " << t.count_deg_1_2() << endl;
    cout << "Degree 1 Nodes :   " << t.count_deg_1() << endl;

    return 0;
}