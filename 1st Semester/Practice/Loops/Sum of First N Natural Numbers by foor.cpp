#include<iostream>
using namespace std;
int main (){
	int num, sum=0;
	cout<<"Enter Number"<<endl;
	cin>>num;
	for(int i=1;i<=num;i++){
		sum=sum+i;
	}
	cout<<"Sum of numbers is : "<<sum;
	
	return 0;
}
