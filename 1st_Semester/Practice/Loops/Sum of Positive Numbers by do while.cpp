#include<iostream>
using namespace std;
int main(){
	int num,sum=0;
	do{
		cout<<"Enter number "<<endl;
		cin>>num;
		sum += num;
	}while(num>0);
	cout<<"the sum of all numbers is : "<<sum;
	return 0;
}
