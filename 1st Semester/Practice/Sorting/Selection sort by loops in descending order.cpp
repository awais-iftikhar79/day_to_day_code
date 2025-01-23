#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int largest_index=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[largest_index]){
				largest_index=j;
			}
		}
		swap(arr[i],arr[largest_index]);
	}
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={3,8,14,6,18};
	int sz=sizeof(arr)/sizeof(int);
	selection_sort(arr,sz);
	cout<<"Thr array in descending order is : ";
	print_array(arr,sz);
	
	return 0;
}

