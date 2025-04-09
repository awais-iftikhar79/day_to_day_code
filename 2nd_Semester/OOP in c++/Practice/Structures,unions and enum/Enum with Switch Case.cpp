#include<iostream>
using namespace std;

enum Days{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};

int main(){
    Days d;
    int choice;
    cout<<"Enter a number from 1-7 "<<endl;
    cin>>choice;
    d=static_cast<Days>(choice);
    cout<<"The coressponding Day is : ";
    switch (d)
    {
    case Monday:
        cout<<"Monday"<<endl;
        break;
    case Tuesday:
        cout<<"Tuesday"<<endl;
        break;
    case Wednesday:
        cout<<"Wednesday"<<endl;
        break;
    case Thursday:
        cout<<"Thursday"<<endl;
        break;
    case Friday:
        cout<<"Friday"<<endl;
        break;
    case Saturday:
        cout<<"Saturday"<<endl;
        break;
    case Sunday:
        cout<<"Sunday"<<endl;
        break;
    }
    return 0;
}