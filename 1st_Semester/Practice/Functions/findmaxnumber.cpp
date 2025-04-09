#include<iostream>
using namespace std;
float findmax(int a,int b,int c){
	int max=a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	return max;
}
int main (){
	int num1,num2,num3,maxnum;
	cout<<"Enter 1st number"<<endl;
	cin>>num1;
	cout<<"Enter 2nd number"<<endl;
	cin>>num2;
	cout<<"Enter 3rd number"<<endl;
	cin>>num3;
	maxnum=findmax(num1,num2,num3);
	cout<<"Greater number is : "<<maxnum;
	return 0;
}
