#include<iostream>
using namespace std;
int sum(int a,int b){
	int z=a+b;
	return z;
}
	int main(){
	int num1,num2;
	cout<<"Enter 1st number"<<endl;
	cin>>num1;
	cout<<"Enter 2nd number"<<endl;
	cin>>num2;
	int s=sum(num1,num2);
	cout<<"The sum of "<<num1<<" and "<<num2<<" is "<<s<<endl;
	
	return 0;
}
