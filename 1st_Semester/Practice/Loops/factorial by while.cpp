#include<iostream>
using namespace std;
int main(){
	int num,f=1,c=1;
	cout<<"Enter number "<<endl;
	cin>>num;
	while(c<=num){
		f=f*c;
		c++;
	}cout<<"Factorial of given number is : "<<f;
	return 0;
}
