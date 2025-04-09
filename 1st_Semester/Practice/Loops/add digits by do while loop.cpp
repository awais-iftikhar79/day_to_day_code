#include<iostream>
using namespace std;
int main(){
	int num,sum=0,remainder;
	cout<<"Enter a positive number "<<endl;
	cin>>num;
	do{
		remainder=num%10;
		sum += remainder;
		num /=10;
	}while(num>0);
	cout<<"The sum of digits is : "<<sum;
	return 0;
	
}
