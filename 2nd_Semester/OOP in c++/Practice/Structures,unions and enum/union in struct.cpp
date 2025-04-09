#include<iostream>
#include<string>
using namespace std;
union value{
    int integer;
    double number;
};
struct measurement
{
    string unit;
    value Value;
};

int main(){
    measurement mea;
    cout<<"enter value"<<endl;
    cin>>mea.Value.integer;
    cin.ignore();
    cout<<"Enter unit of value"<<endl;
    getline(cin,mea.unit);
    cout<<"The value along unit is : "<<mea.Value.integer<<" "<<mea.unit<<endl;
    return 0;
}
