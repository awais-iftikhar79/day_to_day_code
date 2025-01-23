#include<iostream>
using namespace std;
int main(){
	int arr[4]={2,3,4,5};
	int sum=0;
	for(int i=0;i<4;i++){
		sum += arr[i];
	}
	cout<<"The Sum of all numbers is "<<sum;
	return 0;
}
