#include<iostream>
using namespace std;
void selection_sort_recusion(int arr[],int n,int i=0){
	if(i==n-1){
		return ;
	}
	int smallest_index=i;
	for(int j=i+1;j<n;j++){
		if(arr[j]<arr[smallest_index]){
			smallest_index=j;
		}
	}
	swap(arr[i],arr[smallest_index]);
    selection_sort_recusion(arr,n,i+1);
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main (){
	int arr[]={3,6, 18, 14, 8};
	int sz=sizeof(arr)/sizeof(int);
	selection_sort_recusion(arr,sz);
	cout<<"The array is ascending order is ";
	print_array(arr,sz);
	return 0;
}
