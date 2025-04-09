#include<iostream>
using namespace std;
int to_find_reverse(int a){
	int reverse=0,remainder;
	while(a>0){
	remainder=a%10;
	reverse= reverse*10+remainder;
	a /= 10;
    }
	return   reverse;
}

int main(){
	int n,reverse_num;
	cout<<"Enter a number that you want to reverse it"<<endl;
	cin>>n;
	reverse_num=to_find_reverse(n);
	cout<<"The reverse is : "<<reverse_num;
	
	return 0;
}

