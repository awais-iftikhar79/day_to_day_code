#include <iostream>
using namespace std;

struct Incident
{
    int incident_id;
    string description;
    Incident *next;
};

struct Location
{
    int location_id;
    int height;
    Location *l_child;
    Location *r_child;
    Incident_List *inc_head;

    Location(int id) { location_id = id, height = 1, l_child = r_child = nullptr, inc_head; }
};

class Incident_List
{
private:
    Incident *head;

public:
    Incident_List()
    {
        head = nullptr;
    }

    void insert_incident(int id, string dis)
    {
        Incident *new_node = new Incident;

        new_node->incident_id = id;
        new_node->description = dis;

        head = new_node; // updating head
    }

    void delete_incident(int id)
    {
        Incident *current = head;
        Incident *prev = nullptr;

        if (current != nullptr && current->incident_id == id) // for head
        {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->incident_id != id)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Incident not found with ID: " << id << endl; // if not found
            return;
        }

        prev->next = current->next; // remove link
        delete current;
    }

    void display()
    {
        Incident *p = head;
        while (p != nullptr)
        {
            cout << "ID : " << p->incident_id << endl;
            cout << "Description : " << p->description << endl;
            p = p->next;
        }
        cout << "NULL" << endl;
    }
};
// Location Tree
class Location_Tree
{
private:
    Location *root;

public:
    Location_Tree() { root = nullptr; }

    void insertion(int id)
    {
        root = insertion(root, id);
    }
    Location *insertion(Location *p, int id);
    Location *myDelete(Location *p, int id);
    void myDelete(int id) { root = myDelete(root, id); }

    void inorder()
    {
        inorder(root);
    }

    Location *in_pre(Location *p);
    Location *in_succ(Location *p);

    void inorder(Location *p);
    int height(Location *p);
    int balancing_fact(Location *p);

    Location *LL_rotaion(Location *p);
    Location *RR_rotaion(Location *p);
    Location *LR_rotaion(Location *p);
    Location *RL_rotaion(Location *p);
};

int Location_Tree::height(Location *p)
{
    int hl, hr;

    hl = (p && p->l_child) ? p->height : 0;
    hr = (p && p->r_child) ? p->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

Location *Location_Tree::in_pre(Location *p)
{
    while (p && p->r_child != nullptr)
    {
        p = p->r_child;
    }
    return p;
}

Location *Location_Tree::in_succ(Location *p)
{
    while (p && p->l_child != nullptr)
    {
        p = p->l_child;
    }
    return p;
}

int Location_Tree::balancing_fact(Location *p)
{
    int hl, hr;

    hl = (p && p->l_child) ? p->height : 0;
    hr = (p && p->r_child) ? p->height : 0;

    return hl - hr;
}

Location *Location_Tree::LL_rotaion(Location *p)
{
    Location *pl = p->l_child;
    Location *plr = pl->r_child;

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

Location *Location_Tree::RR_rotaion(Location *p)
{
    Location *pr = p->r_child;
    Location *prl = pr->l_child;

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

Location *Location_Tree::LR_rotaion(Location *p)
{
    Location *pl = p->l_child;
    Location *plr = pl->r_child;

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

Location *Location_Tree::RL_rotaion(Location *p)
{
    Location *pr = p->r_child;
    Location *prl = pr->l_child;

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

Location *Location_Tree::insertion(Location *p, int id)
{
    Location *new_Location;

    if (p == nullptr)
    {
        new_Location = new Location(id);
        return new_Location;
    }

    if (id < p->location_id)
    {
        p->l_child = insertion(p->l_child, id);
    }
    else if (id > p->location_id)
    {
        p->r_child = insertion(p->r_child, id);
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

Location *Location_Tree::myDelete(Location *p, int id)
{
    Location *q;
    int balance;

    if (p == nullptr)
    {
        return nullptr;
    }

    if (id > p->data)
    {
        p->r_child = myDelete(p->r_child, id);
    }

    else if (id < p->data)
    {
        p->l_child = myDelete(p->l_child, id);
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
            Location *temp = p->l_child;
            delete p;
            return temp;
        }

        else if (p->l_child == nullptr && p->r_child != nullptr)
        {
            Location *temp = p->r_child;
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

void Location_Tree::inorder(Location *p)
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
    // Incident_List test;
    // test.insert_incident(1001, "Fire");
    // test.display();
    // test.delete_incident(1001);
    return 0;
}