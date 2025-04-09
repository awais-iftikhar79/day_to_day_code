#include<iostream>
using namespace std;
int main(){
	int num,check=0;
	cout<<"Enter a number"<<endl;
	cin>>num;
	for(int i=1;i<=num;i++){
		if(num%i==0){
			check++;
		}
	}
	if(check==2){
		cout<<num<<" is prime number";
	}else{
		cout<<num<<" is not prime number";

	}
	return 0;
}
