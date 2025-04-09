#include<iostream>
using namespace std;
int sum_by_pointer(int* arr,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum += *(arr+i);
	}
	return sum;
}
int main(){
	int n;
	cout<<"Enter the size of an array "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements in an array "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Original array is "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int total_sum=sum_by_pointer(arr,n);
	cout<<"Total sum of elements in an array is :"<<total_sum;
	return 0;
}
