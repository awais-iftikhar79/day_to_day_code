#include<iostream>
using namespace std;
void insertion_sort_recusion(int arr[],int n,int i){
	if(i>=n){
		return;
	}
	int curr=arr[i];
	int prev=i-1;
	while(prev>=0 && arr[prev]<curr){
		arr[prev+1]=arr[prev];
		prev--;
	}
	arr[prev+1]=curr;
	return insertion_sort_recusion(arr,n,i+1);
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={64,34,25,12,22};
	int sz=sizeof(arr)/sizeof(int);
	insertion_sort_recusion(arr,sz,1);
	cout<<"The array in descending order is :";
	print_array(arr,sz);
	return 0;
}
