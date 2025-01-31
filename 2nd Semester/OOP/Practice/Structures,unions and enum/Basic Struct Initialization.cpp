#include <iostream>
#include <string>
using namespace std;

struct Book
{

    string title, author;
    int year;
    float price;
};

int main()
{

    Book newbook;
    cout << "Enter Book title" << endl;
    getline(cin, newbook.title);
    cout << "Enter Author Name" << endl;
    getline(cin, newbook.author);
    cout << "Enter year of publication" << endl;
    cin >> newbook.year;
    cout << "Enter price of book" << endl;
    cin >> newbook.price;
    cin.ignore();

    cout << "Title : " << newbook.title << endl;
    cout << "Author Name : " << newbook.author << endl;
    cout << "Year of Publication : " << newbook.year << endl;
    cout << "Price : Rs." << newbook.price << endl;

    return 0;
}