#include<iostream>
using namespace std;

union Data {
    int integer;
    float point_integer;
    char character;
};
int main(){
    Data data;
    data.integer=4;
    cout<<"The integer stored in it is : "<<data.integer<<endl;
    data.character='A';
    cout<<"The Character stored in it is : "<<data.character<<endl;
    data.point_integer=3.1416;
    cout<<"The float number stored in it is : "<<data.point_integer<<endl;
    return 0;
}