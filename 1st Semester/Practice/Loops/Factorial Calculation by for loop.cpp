#include<iostream>
using namespace std;
int main(){
	int num, factorial=1;
	cout<<"Enter number "<<endl;
	cin>>num;
	for(int i=1;i<=num;i++){
		factorial *= i;
	}
	cout<<"Factorial of given number is : "<<factorial;
	
	return 0;
}
