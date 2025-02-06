#include <iostream>
#include <string>
using namespace std;
class car
{
private:
public:
    string brand;
    int modle;
    float price;
    void enter();
    void display();
};
void car ::enter()
{
    cout << "Enter name of brand of vehicle " << endl;
    getline(cin, brand);
    cout << "Enter model of vehical" << endl;
    cin >> modle;
    cout << "Enter Price of vehicle " << endl;
    cin >> price;
    cin.ignore();
}
void car ::display()
{
    cout << "Brand  : " << brand << endl;
    cout << "Model  : " << modle << endl;
    cout << "Price $: " << price << endl;
}
int main()
{
    car c1, c2;
    c1.enter();
    c2.enter();
    c1.display();
    cout<<"------------"<<endl;
    c2.display();
    return 0;
}