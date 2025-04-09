#include<iostream>
using namespace std;
int main(){
	int arr[6]={56,14,62,33,41,59};
	int* p=arr;
	cout<<"Values in array by pointer are :"<<endl;
	cout<<"At index 0 :"<<*p<<endl;
	cout<<"At index 1 :"<<*p+1<<endl;
	cout<<"At index 2 :"<<*p+2<<endl;
	cout<<"At index 3 :"<<*p+3<<endl;
	cout<<"At index 4 :"<<*p+4<<endl;
	cout<<"At index 5 :"<<*p+5<<endl;
	
	return 0;
}
