#include<iostream>
using namespace std;
int main(){
	int age;
	cout<<"Enter your age :"<<endl;
	cin>>age;
	if(age>0){
		if(age>=65){
			cout<<"You are senior. ";
		}else if(age>=20){
			cout<<"You are adult. ";
		}else if(age>=13){
			cout<<"You are teenager.";
		}else{
			cout<<"You are child.";
		}
	}else{
		cout<<"You are not born yet.";
	}
	return 0;
}
