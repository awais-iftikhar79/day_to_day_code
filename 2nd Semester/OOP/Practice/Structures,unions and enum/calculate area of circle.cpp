#include<iostream>
using namespace std;
struct circle
{
    float radius;
};

void calculate_area(circle* c){
    float area=c->radius*c->radius*3.1415;
    cout<<"The area of corcle is : "<<area<<endl;
}
int main(){
    circle cir;
    cout<<"Enter radius of circle "<<endl;
    cin>>cir.radius;
    calculate_area(&cir);
    return 0;
}