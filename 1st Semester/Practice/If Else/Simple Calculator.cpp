#include<iostream>
using namespace std;
int main(){
	float num1,num2;
	char operations;
	cout<<"Enter 1st number "<<endl;
	cin>>num1;
	cout<<"Enter 2nd number "<<endl;
	cin>>num2;
	cout<<"Enter an operation (+,-,*,/)"<<endl;
	cin>>operations;
	if(operations=='+'){
		cout<<"Result is : "<<num1+num2;
	}else if(operations=='-'){
		cout<<"Result is : "<<num1-num2;
	}else if(operations=='*'){
		cout<<"Result is : "<<num1*num2;
	}else if(operations=='/'){
		if(num2!=0){
			cout<<"Result is : "<<num1/num2;
		}else{
			cout<<"Zero can't be divisible by any number ";
		}
		
	}else{
		cout<<"Invalid operations";
	}
	
	return 0;
}
