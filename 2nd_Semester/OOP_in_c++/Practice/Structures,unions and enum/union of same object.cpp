#include<iostream>
using namespace std;

union value{
    int integer;
    double number;
};
int main(){
    value Value;
    Value.integer=45;
    cout<<"integer is : "<<Value.integer<<endl;
    Value.number=56.7;
    cout<<"The double is : "<<Value.number<<endl;
    cout<<"----------------"<<endl;
    cout<<"The integer is : "<<Value.integer<<endl;
    cout<<"The double number stored in it is :"<<Value.number<<endl;
    return 0;
}