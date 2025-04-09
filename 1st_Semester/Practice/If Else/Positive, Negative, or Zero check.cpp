#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter a number "<<endl;
	cin>>num;
	if(num>0){
		cout<<"The is positive number";
	}else if(num<0){
		cout<<"The is negative number";
	}else{
		cout<<"The number is zero";
	}
	return 0;
}
