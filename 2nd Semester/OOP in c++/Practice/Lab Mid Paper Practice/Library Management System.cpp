#include <iostream>
#include <string>
using namespace std;
#define MAX 100

void display_menu()
{
    cout << "------ LIBARAY MANAGEMENT SYSTEM ------" << endl
         << "1.Add new Book " << endl
         << "2.Add new Member " << endl
         << "3.Issue Book to Member " << endl
         << "4.Retrun Book " << endl
         << "5.Display all Books " << endl
         << "6.Display all members " << endl
         << "7.Display Details of Issued Books" << endl
         << endl;
}
enum BookStatus
{
    Available,
    Issued
};
struct Book
{
    string title;
    string author;
    string isbn;
    BookStatus status;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), status(Available) {}
};
class Member
{
protected:
    string name;
    int mem_id;

public:
    Member(string n, int id) : name(n), mem_id(id) {}
};
class Person
{
protected:
    string name;
    string adress;

public:
    Person(string n, string a) : name(n), adress(a) {}
};
class Student : public Person
{
protected:
    int stu_id;

public:
    Student(string n, string a, int s_id) : Person(n, a), stu_id(s_id) {}
};
class Teacher : public Person
{
protected:
    int tea_id;

public:
    Teacher(string n, string a, int s_id) : Person(n, a), tea_id(s_id) {}
};
class Library
{
private:
    Book *books[MAX];
    Member *members[MAX];
    int book_count;
    int member_count;

public:
    Library() : book_count(0), member_count(0) {}
    void add_new_book(Book *book)
    {
        if (book_count < MAX)
        {
            books[book_count++] = book;
        }
        else
        {
            cout << "Library is full,cannot add more books" << endl;
        }
    }
    void add_member(Member *member)
    {
        if (member_count < MAX)
        {
            members[member_count++] = member;
        }
        else
        {
            cout << "Library is full,cannot add more members" << endl;
        }
    }
    void issuing_book(int member_id, string isbn_book)
    {
        for (int i = 0; i < book_count; i++)
        {
            if (books[i]->isbn == isbn_book && books[i]->status == Available)
            {
                books[i]->status = Issued;
                cout << "Book issued to member " << member_id << endl;
                return;
            }
        }
        cout << "Book not available" << endl;
    }
};
int main()
{

    return 0;
}