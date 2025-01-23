#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter a number"<<endl;
	cin>>num;
	for(int i=num;i>=1;i--){
		for(int j=1;j<=i;j++){
			cout<<i;
		}
		cout<<endl;
	}
	return 0;
	
}
