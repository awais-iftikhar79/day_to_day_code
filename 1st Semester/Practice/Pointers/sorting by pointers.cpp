#include<iostream>
using namespace std;
void sorting_by_pointer(int* arr,int n){
	if(n==1){
		return;
	}
		for(int j=0;j<n-1;j++){
			if(*(arr+j)>*(arr+j+1)){
			swap(*(arr+j),*(arr+j+1));
			}
		}
		sorting_by_pointer(arr,n-1);
	}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[6]={3,6,9,1,0,2};
	cout<<"Original array is : ";
	print(arr,6);
	cout<<endl;
	sorting_by_pointer(arr,6);
	cout<<"Sorted array is : ";
	print(arr,6);
	return 0;
}
