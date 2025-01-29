#include <iostream>
#include <string>
using namespace std;

class Book_mang
{
private:
    string title, author;
    float price;

public:
    Book_mang();
    Book_mang(string n, string a, float p) : title(n), author(a), price(p) {}
    void input()
    {
        cout << "Enter book title" << endl;
        getline(cin, title);
        cout << "Enter author name " << endl;
        getline(cin, author);
        cout << "Enter price of book" << endl;
        cin >> price;
        cin.ignore();
    }
    void display()
    {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Price : $" << price << endl;
    }
};
Book_mang ::Book_mang()
{
    title = "Unknown";
    author = "Unknown";
    price = 0.0;
}
int main()
{
    Book_mang book[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "\n Enter details of " << i + 1 << " book :\n"
             << endl;
        book[i].input();
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Details of " << i + 1 << " book :\n"
             << endl;
        book[i].display();
    }

    return 0;
}