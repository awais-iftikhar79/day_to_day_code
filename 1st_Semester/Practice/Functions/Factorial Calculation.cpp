#include<iostream>
using namespace std;
int factorial(int a){
	int f=1;
	for(int c=1;c<=a;c++){
		f *= c;
	}
	return f;
//	cout<<"Factorial of "<<a<<" is "<<f<<endl;
}
int main (){
	int num,fac_;
	cout<<"Enter number "<<endl;
	cin>>num;
	fac_=factorial(num);
	cout<<"Factorial of given number is : "<<fac_;
	return 0;
}
