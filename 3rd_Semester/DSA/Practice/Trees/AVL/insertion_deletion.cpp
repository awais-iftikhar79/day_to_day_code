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
    Node *myDelete(Node *p, int key);
    void myDelete(int key) { root = myDelete(root, key); }

    void inorder()
    {
        inorder(root);
    }

    Node *in_pre(Node *p);
    Node *in_succ(Node *p);

    void inorder(Node *p);
    int height(Node *p);
    int balancing_fact(Node *p);

    Node *LL_rotaion(Node *p);
    Node *RR_rotaion(Node *p);
    Node *LR_rotaion(Node *p);
    Node *RL_rotaion(Node *p);
};

int AVL::height(Node *p)
{
    int hl, hr;

    hl = (p && p->l_child) ? p->height : 0;
    hr = (p && p->r_child) ? p->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

Node *AVL::in_pre(Node *p)
{
    while (p && p->r_child != nullptr)
    {
        p = p->r_child;
    }
    return p;
}

Node *AVL::in_succ(Node *p)
{
    while (p && p->l_child != nullptr)
    {
        p = p->l_child;
    }
    return p;
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

Node *AVL::LR_rotaion(Node *p)
{
    Node *pl = p->l_child;
    Node *plr = pl->r_child;

    pl->r_child = plr->l_child;
    p->l_child = plr->r_child;

    plr->r_child = p;
    plr->l_child = pl;

    p->height = height(p);
    pl->height = height(pl);
    plr->height = height(plr);

    if (p == root)
        root = plr;

    return plr;
}

Node *AVL::RL_rotaion(Node *p)
{
    Node *pr = p->r_child;
    Node *prl = pr->l_child;

    pr->l_child = prl->r_child;
    p->r_child = prl->l_child;

    prl->r_child = pr;
    prl->l_child = p;

    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);

    if (root == p)
    {
        root = prl;
    }

    return prl;
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
    else if (balancing_fact(p) == -2 && balancing_fact(p->r_child) == -1)
    {
        return RR_rotaion(p);
    }
    else if (balancing_fact(p) == 2 && balancing_fact(p->l_child) == -1)
    {
        return LR_rotaion(p);
    }
    else if (balancing_fact(p) == -2 && balancing_fact(p->r_child) == 1)
    {
        return RL_rotaion(p);
    }

    return p;
}

Node *AVL::myDelete(Node *p, int key)
{
    Node *q;
    int balance;

    if (p == nullptr)
    {
        return nullptr;
    }

    if (key > p->data)
    {
        p->r_child = myDelete(p->r_child, key);
    }

    else if (key < p->data)
    {
        p->l_child = myDelete(p->l_child, key);
    }

    else
    {
        if (p->l_child == nullptr && p->r_child == nullptr)
        {
            delete p;
            return nullptr;
        }

        else if (p->l_child != nullptr && p->r_child == nullptr)
        {
            Node *temp = p->l_child;
            delete p;
            return temp;
        }

        else if (p->l_child == nullptr && p->r_child != nullptr)
        {
            Node *temp = p->r_child;
            delete p;
            return temp;
        }

        else
        {
            if (height(p->l_child) > height(p->r_child))
            {
                q = in_pre(p->l_child);
                p->data = q->data;
                p->l_child = myDelete(p->l_child, q->data);
            }

            else
            {
                q = in_succ(p->r_child);
                p->data = q->data;
                p->r_child = myDelete(p->r_child, q->data);
            }
        }
    }

    p->height = height(p);
    balance = balancing_fact(p);

    if (balancing_fact(p) == 2 && balancing_fact(p->l_child) == 1)
    {
        return LL_rotaion(p);
    }
    else if (balancing_fact(p) == -2 && balancing_fact(p->r_child) == -1)
    {
        return RR_rotaion(p);
    }
    else if (balancing_fact(p) == 2 && balancing_fact(p->l_child) == -1)
    {
        return LR_rotaion(p);
    }
    else if (balancing_fact(p) == -2 && balancing_fact(p->r_child) == 1)
    {
        return RL_rotaion(p);
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

    avl.insertion(30);
    avl.insertion(20);
    avl.insertion(40);
    avl.insertion(10);
    avl.insertion(25);
    avl.insertion(35);
    avl.insertion(50);
    avl.insertion(5);
    avl.insertion(15); // output 5 10 15 20 25 30 35 40 50  (all rorations are used in it)

    avl.inorder();
    cout << endl;
    avl.myDelete(25);
    cout << endl;
    avl.inorder();

    return 0;
}