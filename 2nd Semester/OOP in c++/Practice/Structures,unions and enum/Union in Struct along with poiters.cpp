#include <iostream>
#include <string>
using namespace std;

union Data
{
    int integer;
    float floating_point;
};

struct Items
{
    string name;
    int quantity;
    float price;
    Data data;
};

void enter_details(Items *item)
{
    cout << "Enter item name " << endl;
    cin.ignore();
    getline(cin, item->name);
    cout << "Enter quantity of Items" << endl;
    cin >> item->quantity;
    cout << "Enter price of item" << endl;
    cin >> item->price;
    if (item->quantity > 100)
    {
        cout << "Enter Data (integer)" << endl;
        cin >> item->data.integer;
    }
    else
    {
        cout << "Enter Data (float)" << endl;
        cin >> item->data.floating_point;
    }
    cout << endl;
}

void print(Items *item)
{
    cout << "Product Name : " << item->name << endl;
    cout << "Quantity : " << item->quantity << endl;
    cout << "Price : " << item->price << endl;
    if (item->quantity > 100)
    {
        cout << "Data (integer) : " << item->data.integer << endl;
    }
    else
    {
        cout << "Data (float) : " << item->data.floating_point << endl;
        cout<<"Test commit"<<endl;
    }
    cout << "---------------------" << endl
         << endl;
}
int main()
{
    Items item[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Details of Item " << i + 1 << endl;
        enter_details(&item[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Details of Item " << i + 1 << endl;
        print(&item[i]);
    }

    return 0;
}