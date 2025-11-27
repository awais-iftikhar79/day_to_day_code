#include <iostream>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *l_child;
    Node *r_child;

    Node(int value) { data = value, height = 1, l_child = r_child = nullptr; }
};

class AVL
{
private:
    Node *root;

public:
    AVL() { root = nullptr; }

    void insertion(int key)
    {
        root = insertion(root, key);
    }
    Node *insertion(Node *p, int key);

    void inorder()
    {
        inorder(root);
    }
    void inorder(Node *p);
    int height(Node *p);
    int balancing_fact(Node *p);

    Node *LL_rotaion(Node *p);
    Node *RR_rotaion(Node *p);
};

int AVL::height(Node *p)
{
    int hl, hr;

    hl = (p && p->l_child) ? p->height : 0;
    hr = (p && p->r_child) ? p->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

int AVL::balancing_fact(Node *p)
{
    int hl, hr;

    hl = (p && p->l_child) ? p->height : 0;
    hr = (p && p->r_child) ? p->height : 0;

    return hl - hr;
}

Node *AVL::LL_rotaion(Node *p)
{
    Node *pl = p->l_child;
    Node *plr = pl->r_child;

    pl->r_child = p;
    p->l_child = plr;

    p->height = height(p);
    pl->height = height(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}

Node *AVL::RR_rotaion(Node *p)
{
    Node *pr = p->r_child;
    Node *prl = pr->l_child;

    pr->l_child = p;
    p->r_child = prl;

    p->height = height(p);
    pr->height = height(pr);

    if (root == p)
    {
        root = pr;
    }

    return pr;
}

Node *AVL::insertion(Node *p, int key)
{
    Node *new_node;

    if (p == nullptr)
    {
        new_node = new Node(key);
        return new_node;
    }

    if (key < p->data)
    {
        p->l_child = insertion(p->l_child, key);
    }
    else if (key > p->data)
    {
        p->r_child = insertion(p->r_child, key);
    }

    p->height = height(p);

    if (balancing_fact(p) == 2 && balancing_fact(p->l_child) == 1)
    {
        return LL_rotaion(p);
    }
    else if (balancing_fact(p) == -2 && balancing_fact(p->l_child) == -1)
    {
        return RR_rotaion(p);
    }

    return p;
}

void AVL::inorder(Node *p)
{
    if (p)
    {
        inorder(p->l_child);
        cout << p->data << " ";
        inorder(p->r_child);
    }
}
int main()
{
    AVL avl;
    avl.insertion(10);
    avl.insertion(20);
    avl.insertion(30);

    avl.inorder();

    return 0;
}