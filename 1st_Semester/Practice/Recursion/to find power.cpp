#include<iostream>
using namespace std;
float find_power(int n,int p){
	if(p==0){
		return 1;
	}
	return n*find_power(n,p-1);
}
int main(){
	int num,power;
	cout<<"Enter a number "<<endl;
	cin>>num;
	cout<<"Enter power "<<endl;
	cin>>power;
	cout<<"The Required number is "<<find_power(num,power);
	return 0;
}

