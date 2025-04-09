#include<iostream>
using namespace std;
int main (){
	int a,b;
	cout<<"Enter the value of a"<<endl;
	cin>>a;
	cout<<"Enter the value of b"<<endl;
	cin>>b;
	if(a>b){
		cout<<a<<" is larger than "<<b<<endl;	
	}else if(a==b){
		cout<<"both values are equal "<<endl;
	}else{
		cout<<a<<" is samller than  "<<b<<endl;
	}
	return 0;
}
