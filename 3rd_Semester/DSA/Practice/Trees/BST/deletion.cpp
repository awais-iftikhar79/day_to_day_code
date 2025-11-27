#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *l_child;
    Node *r_child;
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int key);
    Node *Delete(int key) { return Delete(root, key); }
    Node *Delete(Node *root, int key);
    int height(Node *root);
    Node *in_pre(Node *p);
    Node *in_succ(Node *p);
    void inorder() { inorder(root); }
    void inorder(Node *root);
};

void BST::insert(int key)
{

    Node *t = root;
    Node *new_node, *prev;

    if (root == nullptr)
    {
        new_node = new Node;

        new_node->data = key;
        new_node->l_child = new_node->r_child = nullptr;

        root = new_node;
        return;
    }

    while (t)
    {
        prev = t;

        if (key < t->data)
        {
            t = t->l_child;
        }
        else if (key > t->data)
        {
            t = t->r_child;
        }
        else
        {
            return;
        }
    }

    new_node = new Node;

    new_node->data = key;
    new_node->l_child = new_node->r_child = nullptr;

    if (key < prev->data)
    {
        prev->l_child = new_node;
    }
    else
    {
        prev->r_child = new_node;
    }
}

int BST::height(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }

    int x = 0, y = 0;

    x = height(p->l_child);
    y = height(p->r_child);

    return x > y ? x + 1 : y + 1;
}

Node *BST::in_pre(Node *p)
{
    while (p && p->r_child != nullptr)
    {
        p = p->r_child;
    }
    return p;
}

Node *BST::in_succ(Node *p)
{
    while (p && p->l_child != nullptr)
    {
        p = p->l_child;
    }
    return p;
}

Node *BST::Delete(Node *p, int key)
{
    Node *q;

    if (p == nullptr)
    {
        return nullptr;
    }

    if (p->l_child == nullptr && p->r_child == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete (p);
        return nullptr;
    }

    if (key < p->data)
    {
        p->l_child = Delete(p->l_child, key);
    }
    else if (key > p->data)
    {
        p->r_child = Delete(p->r_child, key);
    }
    else
    {
        if (height(p->l_child) > height(p->r_child))
        {
            q = in_pre(p->l_child);
            p->data = q->data;
            p->l_child = Delete(p->l_child, q->data);
        }
        else
        {
            q = in_succ(p->r_child);
            p->data = q->data;
            p->r_child = Delete(p->r_child, q->data);
        }
    }
    return p;
}

void BST::inorder(Node *node)
{
    if (node)
    {
        inorder(node->l_child);
        cout << node->data << " ";
        inorder(node->r_child);
    }
}

int main()
{
    BST bst;

    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    bst.insert(10);
    bst.insert(8);
    bst.insert(12);

    bst.Delete(10);
    bst.inorder();

    return 0;
}