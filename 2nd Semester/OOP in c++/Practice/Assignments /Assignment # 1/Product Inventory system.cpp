#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define CAL_STOCK_VALUE
#define ENABLE_DISCOUNT
#define GENERATE_SALES_REPORT

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
    new_product.discount = 0;

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
        cout << "Product name : " << product[i].product_name << endl;
        cout << "Quantity : " << product[i].product_quantity << endl;
        cout << "Total stock value : $" << total_value << endl;
        cout << "---------------" << endl;
        total_value = 0;
    }
}
#endif

#ifdef ENABLE_DISCOUNT
void add_discount(Product product[], int product_num, int ID)
{
    bool found=false;
    for (int i = 0; i < product_num; i++)
    {
        if (ID == product[i].product_ID)
        {
            if (product[i].discount > 0)
            {
                cout << "Already discount is applied !" << endl;
                return;
            }
            cout << "Enter discount in % : " << endl;
            cin >> product[i].discount;
            if (product[i].discount < 0 || product[i].discount > 100)
            {
                cout << "Invalid Discount " << endl;
                return;
            }
            cout << "Original Price is : $" << product[i].product_price << endl;
            product[i].product_price = product[i].product_price * (1 - (product[i].discount / 100));
            cout << "After discount Price is : $" << product[i].product_price << endl;
            found=true;
        }   
    }
    if(!found){
        cout<<"Product of ID " << ID << " not found !" << endl;
    }
}

#endif
void sale_report(Product product[], int product_num)
{
    double revenue_generated = 0;
    for (int i = 0; i < product_num; i++)
    {
        revenue_generated += product[i].product_price * product[i].product_quantity;
    }
    cout << "Total Revenue Generated is : $" << revenue_generated << endl;
}

void display()
{
    cout << "\nProduct Inventory Management System \n"
         << "1.Add New Product\n"
         << "2.Display Product Details\n"
         << "3.Calculate Total  Stock Value of Each Product\n"
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
#ifdef ENABLE_DISCOUNT
            cout << "Enter product ID " << endl;
            cin >> product_ID;
            add_discount(products, product_count, product_ID);
#endif
            break;
        case 5:
#ifdef GENERATE_SALES_REPORT
            sale_report(products, product_count);
            break;
#endif
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