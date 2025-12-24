#include <iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
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

    Node *search(int key)
    {
        Node *p = root;

        while (p != nullptr)
        {
            if (p->data == key)
            {
                return p;
            }

            if (key < p->data)
            {
                p = p->lchild;
            }

            else if (key > p->data)
            {
                p = p->rchild;
            }
        }

        return nullptr;
    }

    Node *RInsert(Node *p, int key)
    {
        Node *t = new Node;

        if (p == nullptr)
        {
            t->data = key;
            t->lchild = nullptr;
            t->rchild = nullptr;
            return t;
        }

        if (key > p->data)
        {
            p->rchild = RInsert(p->rchild, key);
        }

        else if (key < p->data)
        {
            p->lchild = RInsert(p->lchild, key);
        }

        return p;
    }

    void insert(int key)
    {
        root = RInsert(root, key);
    }

    int height(Node *p)
    { // Height of subtrees to find replacement node while deleting
        int x, y;

        if (p == nullptr)
        {
            return 0;
        }

        x = height(p->lchild);
        y = height(p->rchild);

        if (x > y)
        {
            return x + 1;
        }

        else
        {
            return y + 1;
        }
    }

    Node *InPre(Node *p)
    {
        while (p != nullptr && p->rchild != nullptr)
        {
            p = p->rchild;
        }

        return p;
    }

    Node *InSucc(Node *p)
    {
        while (p != nullptr && p->lchild != nullptr)
        {
            p = p->lchild;
        }

        return p;
    }

    Node *Delete(Node *p, int key)
    {
        Node *q;

        if (p == nullptr)
        { // If our searching pointer p becomes null at any stage return null as there is nothing to delete
            return nullptr;
        }

        if (p->lchild == nullptr && p->rchild == nullptr)
        { // If p is a leaf node
            if (p == root)
            { // If it is root
                root = nullptr;
            }

            delete p;
            return nullptr;
        }

        if (key < p->data)
        { // Search for key
            p->lchild = Delete(p->lchild, key);
        }

        else if (key > p->data)
        { // Search for key
            p->rchild = Delete(p->rchild, key);
        }

        else
        { // Key found
            if (height(p->lchild) > height(p->rchild))
            { // Left subtree greater
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }

            else
            { // Right subtree greater
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }

        return p;
    }

    void Delete(int value)
    {
        root = Delete(root, value);
    }

    void inorder(Node *p)
    {
        if (p)
        {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;

    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    bst.insert(10);
    bst.insert(8);
    bst.insert(12);
    bst.inorder();

    bst.Delete(10);
    bst.inorder();

    return 0;
}