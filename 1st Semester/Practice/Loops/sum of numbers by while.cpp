#include<iostream>
using namespace std;
int main (){
	int i=0,num,sum=0;
	cout<<"Enter number"<<endl;
	cin>>num;
	while(i<=num){
		sum += i;
		i++;
	}cout<<sum<<endl;
	return 0;
}
