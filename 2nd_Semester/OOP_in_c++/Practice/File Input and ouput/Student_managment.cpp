#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
private:
    string name;
    int id;
    float gpa;

public:
    void input()
    {
        cout << "Enter Name of Student " << endl;
        getline(cin, name);
        cout << "Enter ID of Student " << endl;
        cin >> id;
        cout << "Enter GPA of Student " << endl;
        cin >> gpa;
        cin.ignore();
    }

    void save_to_file()
    {
        ofstream outfile("Student.txt", ios::app | ios::trunc);
        outfile << "Student Name : " << name << endl;
        outfile << "Student ID : " << id << endl;
        outfile << "Student GPA : " << gpa << endl
                << endl;

        cout << "Student saved sucessfully" << endl;
        outfile.close();
    }

    void display_students()
    {
        ifstream infile("Student.txt");

        string line;

        cout << "------ DISPLAYING ALL STUDENT RECORD ------" << endl
             << endl;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
    }
};
void menu()
{
    cout << "------ STUDENT MANAGEMENT SYSTEM ------" << endl;
    cout << "1.Add Student " << endl;
    cout << "2.Display All Students " << endl;
    cout << "3.Exit " << endl;
}
int main()
{
    int choice;
    Student s;

    do
    {
        menu();
        cout << "Enter Your Choice " << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            s.input();
            s.save_to_file();
            break;
        case 2:
            s.display_students();
            break;
        case 3:
            exit(0);
            break;

        default:
            cout << "Please Enter correct option " << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}