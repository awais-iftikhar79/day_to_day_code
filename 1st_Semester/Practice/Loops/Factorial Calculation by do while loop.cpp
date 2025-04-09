#include<iostream>
using namespace std;
int main(){
	int num,factorial=1,c=1;
	cout<<"Enter number"<<endl;
	cin>>num;
	do{
		factorial *= c;
		c++;
	}while(c<=num);
	cout<<"The Factorial of given number is :"<<factorial;
	return 0;
}
