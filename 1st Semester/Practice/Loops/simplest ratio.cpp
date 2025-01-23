#include<iostream>
using namespace std;
int gcd(int a,int b){
	
	
	while(b!=0){
		int temp= b;
		b=a%b;
		a=temp;
	}
		return a;

}
int reduce(int &num,int &deno ){ 
		if(num<=0||deno<=0){
		return 0;
        }
    int common_divisor = gcd ( num, deno);
	num /= common_divisor;
	deno /= common_divisor;
    
}
int main(){
	int num1,num2;
	cout<<"Enter number 1"<<endl;
	cin>>num1;
	cout<<"Enter number "<<endl;
	cin>>num2;
	int result=reduce(num1,num2);
	cout<<"Fraction is : "<<num1<<" / "<<num2;
	
	return 0;
}
