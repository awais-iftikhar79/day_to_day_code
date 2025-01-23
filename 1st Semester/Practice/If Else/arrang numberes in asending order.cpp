#include<iostream>
using namespace std;
void ascending_order(float &a,float &b,float &c){
	if(a>c){
		swap(a,b);
	}
	if(a>c){
		swap(a,c);
	}
	if(b>c){
		swap(b,c);
	}
}
int main(){
	float num1,num2,num3;
	cout<<"Enter first number "<<endl;
	cin>>num1;
	cout<<"Enter second number "<<endl;
	cin>>num2;
	cout<<"Enter third number "<<endl;
	cin>>num3;
	cout<<num1<<" "<<num2<<" "<<num3<<endl;
	ascending_order(num1,num2,num3);
	cout<<num1<<" "<<num2<<" "<<num3;
	return 0;
}
