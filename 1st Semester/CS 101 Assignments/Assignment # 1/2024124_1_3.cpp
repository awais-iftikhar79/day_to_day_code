#include <iostream>
#include<cmath>
using namespace std;
int main(){
	float a,b,c,s,area,z;
	cout<<"Enter value of a"<<endl;
	cin>>a;
	cout<<"Enter value of b"<<endl;
	cin>>b;
	cout<<"Enter value of c"<<endl;
	cin>>c;
	s=(a+b+c)/2;
	z=s*(s-a)*(s-b)*(s-c);
	area=sqrt(z);
	cout<<"The area of triangle is : "<<area<<endl;
	return 0;
}
