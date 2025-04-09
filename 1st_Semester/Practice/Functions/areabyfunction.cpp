#include<iostream>
using namespace std;

double calcuarea(double radius){
	double ans=(3.1415)*(radius*radius);
	//return ans;
}
int main(){
	double radius ,area;
	cout<<"Enter radius of circle "<<endl;
	cin>>radius;
	area=calcuarea(radius);
	cout<<"Area of circle with radius "<<radius<<" is : "<<area<<" m^2"<<endl;
	return 0;
}
