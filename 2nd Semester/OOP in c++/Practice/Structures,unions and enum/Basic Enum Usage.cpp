#include<iostream>
using namespace std;

enum Days{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
int main(){
    Days fav_day;
    fav_day=Friday;
    cout<<"Favourite day is : "<<fav_day<<endl;
    return 0;
}
