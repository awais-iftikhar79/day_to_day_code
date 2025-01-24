#include<iostream>
#include<string>
using namespace std;
union details{
    int count;
    float discount;
};

struct Product
{
    string name;
    float price;
    details det;
};

int main(){
    Product p;
    cout<<"Enter product name "<<endl;
    getline(cin,p.name);
    cout<<"Enter price of product"<<endl;
    cin>>p.price;
    int detial_choice;
    cout<<"Enter (0-input stocks ,1-input discout)"<<endl;
    cin>>detial_choice;
    if(detial_choice==0){
        cout<<"Enter stock count"<<endl;
        cin>>p.det.count;
    }else if(detial_choice==1){
        cout<<"Enter discount (i.e 10 for 10%)"<<endl;
        cin>>p.det.discount;
    }
    
    cout<<"\nDetails of product :\n";
    cout<<"Product Name : "<<p.name<<endl;
    cout<<"Product Price : $"<<p.price<<endl;
    if(detial_choice==0){
        cout<<"Stock_count : "<<p.det.count<<endl;
    }else if(detial_choice==1){
        cout<<"Discount : "<<p.det.discount<<"%"<<endl;
    }
    return 0;
}