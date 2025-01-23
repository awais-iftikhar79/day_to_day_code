#include<iostream>
using namespace std;
int main(){
	int table,length;
	cout<<"enter table you want "<<endl;
	cin>>table;
	cout<<"enter length"<<endl;
	cin>>length; 
//while(c<=10){
//	cout<<table*c<<endl;
//	c++;
//}
	for(int c=1;c<=length;c++){
		cout<<table<<"*"<<c<<" = "<<table*c<<endl;
	}
}
