#include<iostream>
using namespace std;
int main(){
	char choice;
	double num,prices,tax;
	do{
	cout<<"Enter number of gallons "<<endl;
	cin>>num;
	
	if (0<num<=100){
		prices=50*num;
	}
	if(num>100){
		prices =5000+ 100*(num-100);
	}
	if(num>350){
		prices =30000+ 150*(num-350);
	}
	if(num>600){
		prices =67500+ 250*(num-600);
	}
	tax=14*0.01*prices;
	prices+=tax;
	cout<<"The total price of gallons is : "<<prices<<endl;
	cout<<"Do want to calculate bill more (Y/N)"<<endl;
	cin>>choice;
    }while(choice=='Y'||choice=='y');
    cout<<"End program"<<endl;
	return 0;
}
