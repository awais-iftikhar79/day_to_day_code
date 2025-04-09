#include<iostream>
using namespace std;
int main(){
	char colour_check[]={
		'g','r','b','o','s','g','g','s','o','b','r','g','r',
		'b','o','s','g','r','r','g','s','o','b','r','b',
		'o','s','g','r','b','b','r','g','s','o','b'};
	int num1,num2;
	cout<<"Enter first number"<<endl;
	cin>>num1;
	cout<<"Enter second number"<<endl;
	cin>>num2;
	if((num1>0 || num1<36) || (num2>0 || num2<36)){
		cout<<"The colour corresponding numbers is  ";
		colour_check[num1-1]==colour_check[num2-1]?cout<<"same":cout<<"different";
	
	}else{
	cout<<"Please enter number is range 1 to 36";
    }
	return 0;
}
