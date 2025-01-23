#include<iostream>
using namespace std;
int main (){
	int age,month,days;
	cout<<"Enter your age: "<<endl;
	cin>>age;
	if(age>0){
	cout<<"you are "<<age<<" years old"<<endl;
	month=age*12;
	cout<<"You are "<<month<<" months old"<<endl;
	days=age*365;
	cout<<"You are "<<days<<" days old"<<endl;
    }else{
    	cout<<" You are not born yet "<<endl;
	}
	return 0;
	
}
