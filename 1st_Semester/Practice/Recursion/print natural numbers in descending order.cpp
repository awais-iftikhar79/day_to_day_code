#include<iostream>
using namespace std;
void descendin(int a){
	if(a==1){
		cout<<a<<" ";
		return;
	}
	cout<<a<<" ";
	descendin(a-1);
}
int main(){
	int num;
	cout<<"Enter a number "<<endl;
	cin>>num;
	cout<<"Descending order is ";
	descendin(num);
	return 0;
}
