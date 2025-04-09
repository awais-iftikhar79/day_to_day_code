#include<iostream>
using namespace std;
void swap_by_pointer(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int x=4,y=9;
	cout<<"Value before swaping : "<<x<<" "<<y<<endl;
	swap_by_pointer(&x,&y);
	cout<<"Values after swaping by pointers : ";
	cout<<x<<" "<<y;
	return 0;
}
