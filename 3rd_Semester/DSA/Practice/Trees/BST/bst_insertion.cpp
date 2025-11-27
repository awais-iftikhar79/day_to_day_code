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
    void r_insert(int key) { r_insert(root, key); };
    void r_insert(Node *&r, int key);
    Node *get_root();
    Node *search(int key);
    void inorder() { inorder(root); }
    void inorder(Node *root);
};

Node *BST::get_root()
{
    return root;
}

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

void BST::r_insert(Node *&p, int key)
{
    Node *new_node;

    if (p == nullptr)
    {
        new_node = new Node;

        new_node->data = key;
        new_node->l_child = new_node->r_child = nullptr;

        p = new_node;
        return;
    }

    if (key < p->data)
    {
        r_insert(p->l_child, key);
    }
    else if (key > p->data)
    {
        r_insert(p->r_child, key);
    }
}

Node *BST::search(int key)
{
    Node *temp = root;

    while (temp)
    {
        if (key == temp->data)
        {
            return temp;
        }
        else if (key < temp->data)
        {
            temp = temp->l_child;
        }
        else if (key > temp->data)
        {
            temp = temp->r_child;
        }
    }
    return nullptr;
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

    // bst.insert(3);
    // bst.insert(5);
    // bst.insert(1)

    bst.r_insert(3);
    bst.r_insert(7);
    bst.r_insert(9);

    bst.inorder();

    Node *res = bst.search(73);

    if (res)
    {
        cout << "Found " << res->data << endl;
    }
    else
    {
        cout << "not Found" << endl;
    }
    return 0;
}