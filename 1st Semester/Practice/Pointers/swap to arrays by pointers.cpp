#include<iostream>
using namespace std;
void swap_by_pointer(int* arr1,int* arr2,int n){
	for(int i=0;i<n;i++){
		swap(*(arr1+i),*(arr2+i));
//	int temp=*(arr1+i);
//	*(arr1+i)=*(arr2+i);
//	*(arr2+i)=temp;
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n;
	cout<<"Enter size of an array "<<endl;
	cin>>n;
	int arr1[n],arr2[n];
	cout<<"Enter elements of 1st array "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cout<<"Enter elements of 2nd array "<<endl;	
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}	
	cout<<"Original arrays are : "<<endl;
	cout<<"1st array is : ";
	print(arr1,n);
	cout<<endl<<"2nd array is : ";
	print(arr2,n);
	cout<<endl<<"After swaping , Arrays are : "<<endl;
	swap_by_pointer(arr1,arr2,n);
	cout<<"1st array is : ";
	print(arr1,n);
	cout<<endl<<"2nd array is : ";
	print(arr2,n);
	return 0;
}
