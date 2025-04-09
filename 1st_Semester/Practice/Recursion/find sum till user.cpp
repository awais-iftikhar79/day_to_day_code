#include<iostream>
using namespace std;
void sum(int a){
	if(a==0){
		return 0;
	}
	return a+sum(a-1);
	
}
int main(){
	int num;
	cout<<"Enter a number "<<endl;
	cin>>num;
	cout<<"The total sum is "<<sum(num);
	return 0;
}
