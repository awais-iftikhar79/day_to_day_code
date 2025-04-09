#include <iostream>
#include <string>
using namespace std;
enum Gradelevel
{
    Freshman,
    Junior,
    Senior
};
string get_grade_level(Gradelevel lvl)
{
    switch (lvl)
    {
    case Freshman:
        return "Freshman";
        break;
    case Senior:
        return "Senior";
        break;
    case Junior:
        return "Junior";
        break;
    default:
        return "Unknown";
        break;
    }
}
struct Studentinfo
{
    string name;
    int student_id;
    Gradelevel gradelvl;
    Studentinfo(string n, int id, Gradelevel lvl) : name(n), student_id(id), gradelvl(lvl) {}
};
union Gradedetails
{
    double percentage;
    struct
    {
        double assignment;
        double exam;
    } Graduate_details;
};
class Student
{
protected:
    Studentinfo stu_info;

public:
    Student(string n, int id, Gradelevel lvl) : stu_info(n, id, lvl) {}
    virtual void cal_grade() = 0;
};
class Undergraduate : public Student
{
    Gradedetails grade_details;

public:
    Undergraduate(string n, int id, Gradelevel lvl, double p) : Student(n, id, lvl)
    {
        grade_details.percentage = p;
    }
    void cal_grade()
    {
        cout << "Undergraduate Grade Calculator" << endl;
        cout << "Name : " << stu_info.name << endl;
        cout << "Grade : " << grade_details.percentage << "%" << endl;
    }
    void display_ug()
    {
        cout << "Name : " << stu_info.name << endl
             << "Student ID : " << stu_info.student_id << endl
             << "Grade Level : " << get_grade_level(stu_info.gradelvl) << endl;
        cout << "Grade : " << grade_details.percentage << "%" << endl;
    }
    int get_ug_id()
    {
        return stu_info.student_id;
    }
};
void find_u_gradaute(Undergraduate *g[], int &ug_count, int id)
{
    bool found = false;
    for (int i = 0; i < ug_count; i++)
    {
        if (g[i]->get_ug_id() == id)
        {
            found = true;
            g[i]->display_ug();
        }
    }
    if (!found)
    {
        cout << "Student with ID " << id << " not found" << endl;
    }
}
class Graduate : public Student
{
private:
    Gradedetails grade_details;
    double weight_grade;

public:
    Graduate(string n, int id, Gradelevel lvl, double assign, double exam) : Student(n, id, lvl)
    {
        grade_details.Graduate_details.assignment = assign;
        grade_details.Graduate_details.exam = exam;
        weight_grade = assign * 30 + exam * 70;
    }

    void cal_grade()
    {
        cout << "Graduate Grade Calculator" << endl;
        cout << "Name : " << stu_info.name << endl;
        cout << "Weigted Grade : " << weight_grade << endl;
    }
    void display_g()
    {
        cout << "Graduate Student Details" << endl;
        cout << "Name : " << stu_info.name << endl;
        cout << "Student ID : " << stu_info.student_id << endl;
        cout << "Grade Level : " << get_grade_level(stu_info.gradelvl) << endl;
        cout << "Weigted Grade : " << weight_grade << endl;
    }
    int get_stu_id()
    {
        return stu_info.student_id;
    }
};

void find_gradaute(Graduate *g[], int &g_count, int id)
{
    bool found = false;
    for (int i = 0; i < g_count; i++)
    {
        if (g[i]->get_stu_id() == id)
        {
            found = true;
            g[i]->display_g();
        }
    }
    if (!found)
    {
        cout << "Student with ID " << id << " not found" << endl;
    }
}
void display_menu()
{
    cout << "------Student Grade System------" << endl
         << "1.Add Undergraduate Student " << endl
         << "2.Add Graduate Student " << endl
         << "3.Display (specific) Graduate Student" << endl
         << "4.Display (specific) undergraduate Student" << endl
         << "5.Display All Students" << endl;
}
void display_grade_level()
{
    cout << "1.Freshman" << endl
         << "2.Senior" << endl
         << "3.Junior" << endl;
}

int main()
{
    const int max = 5;
    int ug_count = 0, g_count = 0, choice;
    Undergraduate *ug_graduates[max];
    Graduate *grauates[max];
    while (true)
    {
        display_menu();
        cout << "Enter your choice " << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string n;
            int id, lvl_no;
            double p;
            Gradelevel lvl;
            cout << "Enter Student name " << endl;
            getline(cin, n);
            display_grade_level();
            cout << "Please Enter your choice " << endl;
            cin >> lvl_no;
            lvl = static_cast<Gradelevel>(lvl_no);
            cout << "Enter Student ID" << endl;
            cin >> id;
            cout << "Enter marks in % " << endl;
            cin >> p;
            ug_graduates[ug_count++] = new Undergraduate(n, id, lvl, p);
        }
        break;
        case 2:
        {
            string n;
            int id, lvl_no;
            double assign, exam;
            Gradelevel lvl;
            cout << "Enter Student name " << endl;
            getline(cin, n);
            display_grade_level();
            cout << "Please Enter your choice " << endl;
            cin >> lvl_no;
            lvl = static_cast<Gradelevel>(lvl_no);
            cout << "Enter Student ID" << endl;
            cin >> id;
            cout << "Enter marks in assignment " << endl;
            cin >> assign;
            cout << "Enter marks in Exam" << endl;
            cin >> exam;
            grauates[g_count++] = new Graduate(n, id, lvl, assign, exam);
        }
        break;
        case 3:
        {
            int id;
            cout << "Enter ID of Student of which you want details" << endl;
            cin >> id;
            find_gradaute(grauates, g_count, id);
        }
        break;
        case 4:
        {
            int id;
            cout << "Enter ID of Student of which you want details" << endl;
            cin >> id;
            find_u_gradaute(ug_graduates, ug_count, id);
        }
        break;
        case 5:
        {
            cout << "Display All Student Details" << endl;
            for (int i = 0; i < ug_count; i++)
            {
                ug_graduates[i]->display_ug();
                cout << "-----------" << endl;
            }
            for (int i = 0; i < g_count; i++)
            {
                grauates[i]->display_g();
                cout << "-----------" << endl;
            }
        }
        break;

        case 6:
        {
            cout << "Exiting The program ....." << endl;
            exit(0);
        }
        break;
        default:
            cout << "invlaid Input !" << endl;
            break;
        }
    }

    return 0;
}