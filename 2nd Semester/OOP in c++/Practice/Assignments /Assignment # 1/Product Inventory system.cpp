#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define CAL_STOCK_VALUE

struct Product
{
    int product_ID;
    string product_name;
    string product_catagory;
    float product_price;
    int product_quantity;
    float discount;
    float revenue_generated;
};

void add_product(Product product[], int &product_num)
{
    if (product_num >= MAX)
    {
        cout << "Limit is full !" << endl;
        return;
    }
    Product new_product;
    cout << "Enter Product ID \n";
    cin >> new_product.product_ID;
    cin.ignore();
    cout << "Enter product name \n";
    getline(cin, new_product.product_name);
    cout << "Enter Product Catagory \n";
    getline(cin, new_product.product_catagory);
    cout << "Enter Price of Product \n";
    cin >> new_product.product_price;
    cout << "Enter Stock of Product\n";
    cin >> new_product.product_quantity;

    new_product.revenue_generated = 0;

    product[product_num] = new_product;
    product_num++;
}

void display_unique_product(Product product[], int product_num, int ID)
{
    bool found = false;
    for (int i = 0; i < product_num; i++)
    {
        if (product[i].product_ID == ID)
        {
            cout << "Product Found !\n"
                 << "Product ID : " << product[i].product_ID << endl
                 << "Product name : " << product[i].product_name << endl
                 << "Product Catagory : " << product[i].product_catagory << endl
                 << "Product Price : $" << product[i].product_price << endl
                 << "Product Stock : " << product[i].product_quantity << endl
                 << "---------------------------------" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Product with " << ID << " not found " << endl;
    }
}
#ifdef CAL_STOCK_VALUE
void cal_stock_value(Product product[], int product_num)
{
    float total_value = 0;
    for (int i = 0; i < product_num; i++)
    {
        total_value += product[i].product_price * product[i].product_quantity;
    }
    cout << "Total Value of all Product is : $" << total_value << endl;
}
#endif

void add_discount(Product product[], int product_num, float discount)
{
    for (int i = 0; i < product_num; i++)
    {
        product[i].product_price = product[i].product_price * (1 - (discount / 100));
    }
}

void display()
{
    cout << "\nProduct Inventory Management System \n"
         << "1.Add New Product\n"
         << "2.Display Product Details\n"
         << "3.Calculate Total  Stock Value\n"
         << "4.Add Discount\n"
         << "5.Generate Sale Report\n"
         << "6.Exit\n";
}

int main()
{
    Product products[MAX];
    int product_count = 0, choice;
    while (true)
    {
        display();
        cout << "Enter Your Choice \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_product(products, product_count);
            break;
        case 2:
            int product_ID;
            cout << "Enter product ID " << endl;
            cin >> product_ID;
            display_unique_product(products, product_count, product_ID);
            break;
        case 3:
#ifdef CAL_STOCK_VALUE
            cal_stock_value(products, product_count);
#endif

            break;
        case 4:
            float discount;
            cout << "Enter percentage of discount \n";
            cin >> discount;
            add_discount(products, product_count, discount);

            break;
        case 5:

            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid Input !" << endl;
            break;
        }
    }
    return 0;
}