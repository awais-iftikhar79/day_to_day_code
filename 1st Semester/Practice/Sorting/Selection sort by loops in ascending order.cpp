#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int smallest_index=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[smallest_index]){
				smallest_index=j;
			}
		}
		swap(arr[i],arr[smallest_index]);
	}
}
void print(int arr[],int sz){
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={5,3,2,7,1};
	int sz=sizeof(arr)/sizeof(int);
	selection_sort(arr,sz);
	print(arr,sz);
	return 0;
}
