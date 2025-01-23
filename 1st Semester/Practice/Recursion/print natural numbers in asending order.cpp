#include<iostream>
using namespace std;
void ascending(int a){
	if(a==1){
		cout<<a<<" ";
		return ;
	}
	 ascending(a-1);
	cout<<a<<" ";
}
int main(){
	int num;
	cout<<"Enter number "<<endl;
	cin>>num;
	cout<<"The Ascending order is ";
	ascending(num);
	
	return 0;
}
