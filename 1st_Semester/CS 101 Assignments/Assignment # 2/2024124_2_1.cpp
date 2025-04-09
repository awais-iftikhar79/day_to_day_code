#include<iostream>
using namespace std;
int reverse_num(int a){
		int reverse =0;
	while(a>0){
	int remainder= a%10;
	reverse=reverse*10+remainder;
	a=a/10;	
	}
	return reverse;
}
int main(){
	int num,reverse_number;
	cout<<"ENter number of which you want inverse"<<endl;
	cin>>num;
	reverse_number=reverse_num(num);
	cout<<"The reverse of given number is : "<<reverse_number;
	return 0;
}
