#include<iostream>
using namespace std;
int main(){
	int num,sum=0,remainder;
	cout<<"Enter a positive number "<<endl;
	cin>>num;
	for(num;num>0;){
		remainder = num%10;
		sum += remainder;
		num /=10;
	}
	cout<<sum;
	return 0;
}
