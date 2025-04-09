#include <iostream>
#include <string>
using namespace std;

class book
{
private:
    string title, author, publisher;

public:
    void set_details()
    {
        cout << "Enter book title " << endl;
        getline(cin, title);
        cout << "Enter author name " << endl;
        getline(cin, author);
        cout << "Enter publisher name " << endl;
        getline(cin, publisher);
    }
    void print_details()
    {
        cout << "\nDetails of book are : \n\n";
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Publisher : " << publisher << endl;
    }
};
int main()
{
    book b;
    b.set_details();
    b.print_details();
    return 0;
}