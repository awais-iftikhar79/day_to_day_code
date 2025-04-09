#include<iostream>
using  namespace std;
int main(){
	int arr[4]={2,3,4,5};
	int product=1;
	for(int i=0;i<4;i++){
		product *= arr[i];
	}
	cout<<"The product of all elemnts is "<<product;
	return 0;
}
