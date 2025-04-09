#include<iostream>
using namespace std;
int main(){
	int x=5;
	int* p=&x;
	cout<<"Value of varialbe "<<x<<endl;
	cout<<"Value by pointer is :"<<*p;
	return 0;
}
