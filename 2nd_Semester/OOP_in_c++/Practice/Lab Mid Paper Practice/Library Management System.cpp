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
         << "8.Exit " << endl;
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

class Person
{
protected:
    string name;
    string adress;

public:
    Person(string n, string a) : name(n), adress(a) {}
};
class Member : public Person
{
protected:
    int mem_id;

public:
    Member(string n, string adr, int id) : Person(n, adr), mem_id(id) {}
    int getID()
    {
        return mem_id;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Adress : " << adress << endl;
        cout << "Member ID : " << mem_id << endl;
    }
};
class Student : public Member
{
protected:
    int stu_id;

public:
    Student(string n, string a, int id, int s_id) : Member(n, a, id), stu_id(s_id) {}
};
class Teacher : public Member
{
protected:
    int tea_id;

public:
    Teacher(string n, string a, int id, int t_id) : Member(n, a, id), tea_id(t_id) {}
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
        bool member_found = false;
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->getID() == member_id)
            {
                member_found = true;
                break;
            }
        }
        if (!member_found)
        {
            cout << "Member not found.Book cannot be issued !" << endl;
            return;
        }

        for (int i = 0; i < book_count; i++)
        {
            if (books[i]->isbn == isbn_book && books[i]->status == Available)
            {
                books[i]->status = Issued;
                cout << "Book issued to member " << member_id << " sucessfully !" << endl;
                return;
            }
        }
        cout << "Book not available" << endl;
    }
    void return_book(string isbn_book)
    {
        for (int i = 0; i < book_count; i++)
        {
            if (books[i]->isbn == isbn_book && books[i]->status == Issued)
            {
                books[i]->status = Available;
                cout << "Book returned suceesfully !" << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }
    void display_all_books()
    {
        for (int i = 0; i < book_count; i++)
        {
            cout << "Book Name : " << books[i]->title << endl
                 << "Author : " << books[i]->author << endl
                 << "ISBN : " << books[i]->isbn << endl
                 << "Status : " << ((books[i]->status == Available) ? "Available" : "Issued") << endl
                 << "        --------------------       " << endl;
        }
    }
    void display_issued_books()
    {
        for (int i = 0; i < book_count; i++)
        {
            if (books[i]->status == Issued)
            {
                cout << "Book Name : " << books[i]->title << endl
                     << "Author : " << books[i]->author << endl
                     << "ISBN : " << books[i]->isbn << endl
                     << "Status : " << ((books[i]->status == Available) ? "Available" : "Issued") << endl
                     << "        --------------------       " << endl;
            }
        }
    }
    void display_all_members()
    {
        for (int i = 0; i < member_count; i++)
        {
            members[i]->display();
            cout << "        --------------------       " << endl;
        }
    }
    ~Library()
    {
        for (int i = 0; i < book_count; i++)
        {
            delete books[i];
        }
        for (int i = 0; i < member_count; i++)
        {
            delete members[i];
        }
    }
};
int main()
{
    Library library;
    int choice;
    while (true)
    {
        display_menu();
        cout << "Please Enter your choice" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string title, author, isbn;
            cout << "Enter Book name " << endl;
            getline(cin, title);
            cout << "Enter Author name" << endl;
            getline(cin, author);
            cin.ignore();
            cout << "Enter ISBN number " << endl;
            cin >> isbn;

            Book *new_book = new Book(title, author, isbn);
            library.add_new_book(new_book);
            cout << "Book added sucessfully !" << endl;
        }
        break;
        case 2:
        {
            int type_choice, id;
            string name, adress;
            cout << "Enter name " << endl;
            getline(cin, name);
            cout << "Enter Address " << endl;
            getline(cin, adress);
            cout << "Enter Member ID " << endl;
            cin >> id;

            cout << "1.For Student " << endl
                 << "2.For Teacher " << endl
                 << "Enter you choice " << endl;
            cin >> type_choice;
            if (type_choice == 1)
            {
                int stu_id;
                cout << "Enter Student ID " << endl;
                cin >> stu_id;
                Student *new_student = new Student(name, adress, id, stu_id);
                library.add_member(new_student);
                cout << "Student added sucessfully !" << endl;
            }
            else
            {
                int t_id;
                cout << "Enter Teacher ID " << endl;
                cin >> t_id;
                Teacher *new_teacher = new Teacher(name, adress, id, t_id);
                library.add_member(new_teacher);
                cout << "Teacher added sucessfully !" << endl;
            }
            break;
        }

        case 3:
        {
            int member_id;
            string isbn;
            cout << "Enter Member ID " << endl;
            cin >> member_id;
            cin.ignore();
            cout << "Enter ISBN numer of Book " << endl;
            getline(cin, isbn);
            library.issuing_book(member_id, isbn);
            break;
        }
        case 4:
        {
            string isbn;
            cout << "Enter ISBN number of Returning Book" << endl;
            getline(cin, isbn);
            library.return_book(isbn);
        }
        break;
        case 5:
            library.display_all_books();
            break;
        case 6:
            library.display_all_members();
            break;
        case 7:
            library.display_issued_books();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}