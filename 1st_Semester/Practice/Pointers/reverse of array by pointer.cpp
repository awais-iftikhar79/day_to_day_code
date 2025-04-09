#include<iostream>
using namespace std;
int main(){
	int arr[]={3,4,5,6,7,8};
	cout<<"Original array is ";
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int s=0,e=5;
	while(s<e){
		swap(*(arr+s),*(arr+e));
		s++;
		e--;
	}

	cout<<"Reverse array is : ";
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

