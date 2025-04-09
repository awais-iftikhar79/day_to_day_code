#include<iostream>
//#include<cmath>
using namespace std;
int main(){
	const double pi=3.1415;
	double radius,area,volume,sqr,cube,circumference;
	cout<<"Enter radius of sphere: ";
	cin>>radius;
	sqr=radius*radius;
	cube=sqr*radius;
//	sqr =pow(radius,radius);
	area=4*pi*sqr;
	cout<<" The area of sphere is :"<<area<<endl;
	volume=(4*pi*cube)/3;
	cout<<" The circumference of sphere is :"<<volume<<endl;
	cout<<"The volume of sphere is : "<<volume<<endl;

	return 0;
	
}
