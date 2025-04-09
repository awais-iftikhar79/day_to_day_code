#include<iostream>
#include<cmath>
using namespace std;
int count_digits(int a){
	if(a==0){
		return 0;
	}
	if(a<0){
		a=abs(a);
	}
	return 1+count_digits(a/10);
}
int main(){
	int num;
	cout<<"Enter a number "<<endl;
	cin>>num;
	cout<<"Number of digits in your number are "<<count_digits(num);
}
