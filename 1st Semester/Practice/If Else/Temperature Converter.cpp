#include<iostream>
using namespace std;
int main(){
	float celsius,faranheit;
	cout<<"Enter temperature in celsius"<<endl;
	cin>>celsius;
	faranheit=(celsius*9/5)+32;
	cout<<"Temperature in Faranheit "<<faranheit<<"F"<<endl;
	if(faranheit<32){
		cout<<"Temperature is below freezing point ";
	}else{
			cout<<"Temperature is higher than freezing point";
	}
	
	return 0;
}
