#include <iostream>
#include <string>
using namespace std;

// ---------------------- Incident Linked List ----------------------
struct Incident
{
    int incident_id;
    string description;
    Incident *next;
};

class Incident_List
{
private:
    Incident *head;

public:
    Incident_List() { head = nullptr; }

    ~Incident_List()
    {
        Incident *p = head;
        while (p != nullptr)
        {
            Incident *nxt = p->next;
            delete p;
            p = nxt;
        }
        head = nullptr;
    }

    bool insert_incident(int id, const string &dis)
    {
        // prevent duplicate incident IDs in the same location
        Incident *p = head;
        while (p != nullptr)
        {
            if (p->incident_id == id)
            {
                cout << "Incident already exists" << endl;
                return false;
            }
            p = p->next;
        }

        Incident *new_node = new Incident;
        new_node->incident_id = id;
        new_node->description = dis;

        // insert at head
        new_node->next = head;
        head = new_node;
        return true;
    }

    bool delete_incident(int id)
    {
        Incident *current = head;
        Incident *prev = nullptr;

        while (current != nullptr)
        {
            if (current->incident_id == id)
            {
                if (prev == nullptr) // deleting head
                    head = current->next;
                else
                    prev->next = current->next;

                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    void display() const
    {
        Incident *p = head;
        if (p == nullptr)
        {
            cout << "    (no incidents)\n";
            return;
        }

        while (p != nullptr)
        {
            cout << "    ID: " << p->incident_id << " | Description: " << p->description << "\n";
            p = p->next;
        }
    }
};

// ---------------------- Location (AVL Node) ----------------------
struct Location
{
    int location_id;
    string area;
    string city;

    int height;
    Location *l_child;
    Location *r_child;

    Incident_List *inc_head; // pointer to linked list object

    Location(int id, const string &a, const string &c)
    {
        location_id = id;
        area = a;
        city = c;

        height = 1;
        l_child = nullptr;
        r_child = nullptr;

        inc_head = new Incident_List();
    }

    ~Location()
    {
        delete inc_head; // frees all incidents too
        inc_head = nullptr;
    }
};

// ---------------------- Location AVL Tree ----------------------
class Location_Tree
{
private:
    Location *root;

    int nodeHeight(Location *p)
    {
        if (p == nullptr)
            return 0;

        int hl = (p->l_child != nullptr) ? p->l_child->height : 0;
        int hr = (p->r_child != nullptr) ? p->r_child->height : 0;

        return (hl > hr) ? (hl + 1) : (hr + 1);
    }

    int balanceFactor(Location *p)
    {
        if (p == nullptr)
            return 0;

        int hl = (p->l_child != nullptr) ? p->l_child->height : 0;
        int hr = (p->r_child != nullptr) ? p->r_child->height : 0;

        return hl - hr;
    }

    Location *LL_rotation(Location *p)
    {
        Location *pl = p->l_child;
        Location *plr = pl->r_child;

        pl->r_child = p;
        p->l_child = plr;

        p->height = nodeHeight(p);
        pl->height = nodeHeight(pl);

        return pl;
    }

    Location *RR_rotation(Location *p)
    {
        Location *pr = p->r_child;
        Location *prl = pr->l_child;

        pr->l_child = p;
        p->r_child = prl;

        p->height = nodeHeight(p);
        pr->height = nodeHeight(pr);

        return pr;
    }

    Location *LR_rotation(Location *p)
    {
        p->l_child = RR_rotation(p->l_child);
        return LL_rotation(p);
    }

    Location *RL_rotation(Location *p)
    {
        p->r_child = LL_rotation(p->r_child);
        return RR_rotation(p);
    }

    Location *insertRec(Location *p, int id, const string &area, const string &city)
    {
        if (p == nullptr)
            return new Location(id, area, city);

        if (id < p->location_id)
            p->l_child = insertRec(p->l_child, id, area, city);
        else if (id > p->location_id)
            p->r_child = insertRec(p->r_child, id, area, city);
        else
        {
            cout << "Error: Location ID already exists.\n";
            return p;
        }

        p->height = nodeHeight(p);

        // Balance
        if (balanceFactor(p) == 2 && balanceFactor(p->l_child) >= 0)
            return LL_rotation(p);
        if (balanceFactor(p) == 2 && balanceFactor(p->l_child) < 0)
            return LR_rotation(p);
        if (balanceFactor(p) == -2 && balanceFactor(p->r_child) <= 0)
            return RR_rotation(p);
        if (balanceFactor(p) == -2 && balanceFactor(p->r_child) > 0)
            return RL_rotation(p);

        return p;
    }

    Location *in_succ(Location *p)
    {
        while (p && p->l_child != nullptr)
            p = p->l_child;
        return p;
    }

    Location *in_pre(Location *p)
    {
        while (p && p->r_child != nullptr)
        {
            p = p->r_child;
        }
        return p;
    }

    Location *deleteRec(Location *p, int id, bool &removed)
    {
        Location *q;
        int balance;

        if (p == nullptr)
        {
            return nullptr;
        }

        if (id > p->location_id)
        {
            p->r_child = deleteRec(p->r_child, id, removed);
        }
        else if (id < p->location_id)
        {
            p->l_child = deleteRec(p->l_child, id, removed);
        }
        else
        {
            removed = true;

            // 0 child
            if (p->l_child == nullptr && p->r_child == nullptr)
            {
                delete p; // destructor deletes incidents
                return nullptr;
            }

            // 1 child (left)
            else if (p->l_child != nullptr && p->r_child == nullptr)
            {
                Location *temp = p->l_child;
                delete p; // destructor deletes incidents
                return temp;
            }

            // 1 child (right)
            else if (p->l_child == nullptr && p->r_child != nullptr)
            {
                Location *temp = p->r_child;
                delete p; // destructor deletes incidents
                return temp;
            }

            // 2 children
            else
            {
                if (nodeHeight(p->l_child) > nodeHeight(p->r_child))
                {
                    // use inorder predecessor
                    q = in_pre(p->l_child);

                    // delete incidents of the location being removed (current node)
                    // (assumes deleting inc_head frees the whole list)
                    delete p->inc_head;
                    p->inc_head = nullptr;

                    // copy predecessor data into current node
                    p->location_id = q->location_id;
                    p->inc_head = q->inc_head;

                    // detach so q destructor won't delete moved incidents
                    q->inc_head = nullptr;

                    // delete predecessor node from left subtree
                    p->l_child = deleteRec(p->l_child, q->location_id, removed);
                }
                else
                {
                    // use inorder successor
                    q = in_succ(p->r_child);

                    delete p->inc_head;
                    p->inc_head = nullptr;

                    p->location_id = q->location_id;
                    p->inc_head = q->inc_head;

                    q->inc_head = nullptr;

                    p->r_child = deleteRec(p->r_child, q->location_id, removed);
                }
            }
        }

        if (p == nullptr)
        {
            return nullptr;
        }

        p->height = nodeHeight(p);

        if (balanceFactor(p) == 2 && balanceFactor(p->l_child) >= 0)
        {
            return LL_rotation(p);
        }
        else if (balanceFactor(p) == -2 && balanceFactor(p->r_child) <= 0)
        {
            return RR_rotation(p);
        }
        else if (balanceFactor(p) == 2 && balanceFactor(p->l_child) < 0)
        {
            return LR_rotation(p);
        }
        else if (balanceFactor(p) == -2 && balanceFactor(p->r_child) > 0)
        {
            return RL_rotation(p);
        }

        return p;
    }

    void inorderRec(Location *p) const
    {
        if (p != nullptr)
        {
            inorderRec(p->l_child);

            cout << "Location ID: " << p->location_id
                 << " | Area: " << (p->area.empty() ? "-" : p->area)
                 << " | City: " << (p->city.empty() ? "-" : p->city)
                 << " | Height: " << p->height << "\n";
            p->inc_head->display();

            inorderRec(p->r_child);
        }
    }

    Location *searchRec(Location *p, int id) const
    {
        while (p != nullptr)
        {
            if (id < p->location_id)
                p = p->l_child;
            else if (id > p->location_id)
                p = p->r_child;
            else
                return p;
        }
        return nullptr;
    }

    void destroy(Location *p)
    {
        if (p == nullptr)
            return;
        destroy(p->l_child);
        destroy(p->r_child);
        delete p;
    }

public:
    Location_Tree() { root = nullptr; }

    ~Location_Tree() { destroy(root); }

    void insert_location(int id, const string &area, const string &city)
    {
        root = insertRec(root, id, area, city);
    }

    void delete_location(int id)
    {
        bool removed = false;
        root = deleteRec(root, id, removed);
        if (removed)
            cout << "Location removed (and all its incidents).\n";
        else
            cout << "Location not found.\n";
    }

    void add_incident(int location_id, int incident_id, const string &desc)
    {
        Location *loc = searchRec(root, location_id);
        if (loc == nullptr)
        {
            cout << "Error: Location not found. Add the location first.\n";
            return;
        }

        if (loc->inc_head->insert_incident(incident_id, desc))
            cout << "Incident added.\n";
        else
            cout << "Error: Incident ID already exists for this location.\n";
    }

    void remove_incident(int location_id, int incident_id)
    {
        Location *loc = searchRec(root, location_id);
        if (loc == nullptr)
        {
            cout << "Location not found.\n";
            return;
        }

        if (loc->inc_head->delete_incident(incident_id))
            cout << "Incident deleted.\n";
        else
            cout << "Incident not found.\n";
    }

    void display_inorder() const
    {
        cout << "\n--- ERMS (In-order AVL Traversal) ---\n";
        inorderRec(root);
        cout << "------------------------------------\n";
    }
};

void menu()
{
    cout << "\n1) Add location\n";
    cout << "2) Remove location\n";
    cout << "3) Add incident\n";
    cout << "4) Delete incident\n";
    cout << "5) Display all (in-order)\n";
    cout << "0) Exit\n";
    cout << "Choose: ";
}
// ---------------------- Main (simple menu) ----------------------
int main()
{
    Location_Tree t;

    int choice;
    while (true)
    {
        menu();
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1)
        {
            int id;
            cout << "Enter location ID: ";
            cin >> id;

            cin.ignore(); // clear newline before getline
            string area, city;
            cout << "Enter area: ";
            getline(cin, area);
            cout << "Enter city: ";
            getline(cin, city);

            t.insert_location(id, area, city);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter location ID to remove: ";
            cin >> id;
            t.delete_location(id);
        }
        else if (choice == 3)
        {
            int loc, inc;
            cout << "Enter location ID: ";
            cin >> loc;
            cout << "Enter incident ID: ";
            cin >> inc;

            cin.ignore(); // clear newline before getline
            string desc;
            cout << "Enter description: ";
            getline(cin, desc);

            t.add_incident(loc, inc, desc);
        }
        else if (choice == 4)
        {
            int loc, inc;
            cout << "Enter location ID: ";
            cin >> loc;
            cout << "Enter incident ID to delete: ";
            cin >> inc;

            t.remove_incident(loc, inc);
        }
        else if (choice == 5)
        {
            t.display_inorder();
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
