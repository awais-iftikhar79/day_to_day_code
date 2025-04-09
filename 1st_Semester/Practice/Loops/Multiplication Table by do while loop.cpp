#include<iostream>
using namespace std;
int main(){
	int table,length,c=1;
	cout<<"Enter table"<<endl;
	cin>>table;
	cout<<"Enter length"<<endl;
	cin>>length;
	cout<<"The table of "<<table<<" is :"<<endl;
	do{
	cout<<table<<"*"<<length<<" = "<<table*length<<endl;
	c++;
	}while(c<=length);
	return 0;
	
}
