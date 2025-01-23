#include<iostream>
using namespace std;
void Insertion_sort(int arr[],int n){
	for(int i=1;i<n;i++){
		int curr=arr[i];
		int prev=i-1;
		while(prev>=0 && arr[prev]>curr){
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=curr;
	}
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={6,4,8,3,2};	
	int sz=sizeof(arr)/sizeof(int);
	Insertion_sort(arr,sz);
	cout<<"The array in ascending order is ";
	print_array(arr,sz);
	
	return 0;
}
