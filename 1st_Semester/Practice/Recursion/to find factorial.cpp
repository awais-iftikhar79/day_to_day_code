#include<iostream>
using namespace std;
int fact(int a){
	if(a==0||a==1){
		return 1;
	}
	return a*fact(a-1);
}
int main(){
	int num;
	cout<<"Enter number of which you want factorial "<<endl;
	cin>>num;
	cout<<"The factorial is "<<fact(num);
	return 0;
}
