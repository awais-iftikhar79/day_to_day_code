#include<iostream>
using namespace std;
void selection_sort_recusion(int arr[],int n,int i=0){
	if(i==n-1){
		return ;
	}
	int largest_index=i;
	for(int j=i+1;j<n;j++){
		if(arr[j]>arr[largest_index]){
			largest_index=j;
		}
	}
	swap(arr[i],arr[largest_index]);
	return selection_sort_recusion(arr,n,i+1);
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main (){
	int arr[]={3,6, 8, 14, 18};
	int sz=sizeof(arr)/sizeof(int);
	selection_sort_recusion(arr,sz);
	cout<<"The array is descending order is ";
	print_array(arr,sz);
	return 0;
}
