#include <iostream>
#include <string>
using namespace std;

// ---------------------------------- Student linked list -----------------------------
struct StudentNode
{
    int roll;
    float marks;
    string name;
    StudentNode *next;
};

class Student_list
{
private:
    StudentNode *head;

public:
    Student_list()
    {
        head = nullptr;
    }

    void add_student(int r, float m, string n, int index)
    {
        if (index < 0 || index > count_nodes())
        {
            cout << "Invalid Index !" << endl;
            return;
        }
        StudentNode *new_stu = new StudentNode;
        new_stu->marks = m;
        new_stu->name = n;
        new_stu->roll = r;

        if (index == 0)
        {
            if (head == nullptr)
            {
                new_stu->next = head;
                head = new_stu;
                return;
            }
            new_stu->next = head;
            head = new_stu;
        }
        else
        {
            StudentNode *p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_stu->next = p->next;
            p->next = new_stu;
        }
    }

    void insert_Deleted(int r, string n, float m)
    {
        StudentNode *new_stu = new StudentNode;
        new_stu->roll = r;
        new_stu->name = n;
        new_stu->marks = m;
        new_stu->next = head;
        head = new_stu;
    }

    bool delete_Student(int r, int &droll, float &dmark, string &dname)
    {
        if (!head)
        {
            cout << "Record list is empty !" << endl;
            return false;
        }
        StudentNode *p = head, *q = nullptr;

        while (p && p->roll != r)
        {
            q = p;
            p = p->next;
        }
        if (p == nullptr)
        {
            cout << "No Reord found " << endl;
            return false;
        }

        droll = p->roll;
        dname = p->name;
        dmark = p->marks;

        if (p == head)
        {
            head = head->next;
        }
        else
        {
            q->next = p->next;
        }
        delete (p);
        cout << "Student deleted sucessfully !" << endl;
        return true;
    }

    void bubble_sort()
    {
        int count = count_nodes();

        for (int i = 0; i < count - 1; i++)
        {
            StudentNode *p = head;
            for (int j = 0; j < count - 1 - i; j++)
            {
                if (p->marks > p->next->marks)
                {
                    swap(p->marks, p->next->marks);
                    swap(p->name, p->next->name);
                    swap(p->roll, p->next->roll);
                }
                p = p->next;
            }
        }
        cout << "Student marks are sorted" << endl;
    }

    int count_nodes()
    {
        if (!head)
        {
            return 0;
        }
        StudentNode *p = head;
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void display_student_record()
    {
        if (!head)
        {
            cout << "Record List is empty !" << endl;
            return;
        }
        StudentNode *p = head;
        cout << "====== DISPLAYING STUDENT RECORD ======" << endl;
        while (p)
        {
            cout << "Name : " << p->name << "\nRoll : " << p->roll << "\nMarks : " << p->marks << endl
                 << endl;
            p = p->next;
        }
    }
};
//   ------------------------------ Stack ------------------------------
struct StackNode
{
    int roll;
    string name;
    float marks;
    StackNode *next;
};

class Stack
{
private:
    StackNode *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void push(int r, string n, float m)
    {
        StackNode *del_stu = new StackNode;
        del_stu->roll = r;
        del_stu->name = n;
        del_stu->marks = m;
        del_stu->next = top;
        top = del_stu;
    }

    bool is_empty()
    {
        return top == nullptr;
    }

    bool pop(int &r, string &n, float &m)
    {
        if (is_empty())
        {
            cout << "Stack is empty !" << endl;
            return false;
        }
        StackNode *p = top;
        r = p->roll;
        n = p->name;
        m = p->marks;
        top = top->next;
        delete (p);
        return true;
    }
};

// ------------------------------------ Queue ---------------------------
struct QNode
{
    int roll;
    QNode *next;
};

class Queue
{
private:
    QNode *front, *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int r)
    {
        QNode *node = new QNode;
        node->roll = r;
        node->next = nullptr;

        if (front == nullptr)
        {
            front = rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }

    bool is_empty()
    {
        return front == nullptr;
    }

    void display_roll_no()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        QNode *p = front;
        cout << "======== DISPLAY STUDENT ROLL NUMBER =======" << endl;
        while (p)
        {
            cout << p->roll << endl;
            p = p->next;
        }
        cout << endl;
    }
};

void menu()
{
    cout << "Student Management System" << endl;
    cout << "1-Add Student " << endl
         << "2-Display Students" << endl
         << "3-Delete Student" << endl
         << "4-Undo Student" << endl
         << "5-Sort Student By Marks" << endl
         << "6-Display ROll Numbers" << endl
         << endl;
}

int main()
{
    Student_list stu_list;
    Stack del_stu;
    Queue reg_queue;

    int choice;
    do
    {
        menu();
        cout << "Enter your choice " << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            int roll, idx;
            float marks;
            string name;

            cout << "Enter student roll number" << endl;
            cin >> roll;
            cout << "Enter marks of student" << endl;
            cin >> marks;
            cin.ignore();
            cout << "Enter student name" << endl;
            getline(cin, name);
            cout << "Enter index :" << endl;
            cin >> idx;

            stu_list.add_student(roll, marks, name, idx);
            reg_queue.enqueue(roll);
        }
        break;

        case 2:
        {
            stu_list.display_student_record();
        }

        break;
        case 3:
        {
            int roll, droll;
            float dmark;
            string dname;
            cout << "Enter Roll number" << endl;
            cin >> roll;

            if (stu_list.delete_Student(roll, droll, dmark, dname))
            {
                del_stu.push(droll, dname, dmark);
            }
        }

        break;
        case 4:
        {
            int r;
            float m;
            string n;

            if (del_stu.pop(r, n, m))
            {
                stu_list.insert_Deleted(r, n, m);
            }
        }

        break;
        case 5:
        {
            stu_list.bubble_sort();
        }

        break;
        case 6:
        {
            reg_queue.display_roll_no();
        }

        break;
        case 7:
        {
            cout << "Exititng Program !" << endl;
        }

        break;

        default:
            cout << "Invalid Input !" << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}