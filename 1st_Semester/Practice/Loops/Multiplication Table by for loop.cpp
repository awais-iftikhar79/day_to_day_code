#include<iostream>
using namespace std;
int main(){
	int table,length;
	cout<<"enter talbe number "<<endl;
	cin>>table;
	cout<<"enter length "<<endl;
	cin>>length;
	for(int i=1;i<=length;i++){
		cout<<table<<"*"<<length<<" = "<<table*length<<endl;
	}
	return 0;
}
