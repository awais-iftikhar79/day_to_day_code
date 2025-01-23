#include<iostream>
using namespace std;
int sumnum(int a,int b){
	int z=a+b;
}
int main(){
	int num1,num2,sum;
	cout<<"Enter num1 "<<endl;
	cin>>num1;
	cout<<"Enter num2 "<<endl;
	cin>>num2;
	sum=sumnum(num1,num2);
	cout<<"The sum of two numbers is : "<<sum;
	return 0;
}
