#include<iostream>
#include<cmath>
using namespace std;
int main (){
	double num,power,newnum;
	cout<<"Enter the number"<<endl;
	cin>>num;
    cout<<"Enter power ";
	cin>>power;
	newnum=pow(num,power);
	cout<<"The power of "<<num<<" with "<<power<<" is: "<<newnum<<endl;
	
	return 0;
}
