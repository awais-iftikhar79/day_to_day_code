#include<iostream>
using namespace std;

enum Days{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};

int main(){
    int fav_day;
    cout<<"Enter value "<<endl;
    cin>>fav_day;
    switch (fav_day)
    {
    case 1:
        cout<<"Monday";
        break;
    case 2:
        cout<<"Tuesday";
        break;    
    case 3:
        cout<<"Wednesday";
        break;
    case 4: 
        cout<<"Thursday";
        break;
    case 5:
        cout<<"Friday";
        break;
    case 6:
        cout<<"Saturday";
        break;
    case 7:
        cout<<"Sunday";
        break;            
    default:
    cout<<"Invalid value";
        break;
    }

    return 0;
}
