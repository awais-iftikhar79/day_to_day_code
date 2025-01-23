#include<iostream>
using namespace std;
void Bubble_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]<arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={7,4,5,1,3};
	int sz=sizeof(arr)/sizeof(int);
	Bubble_sort(arr,sz);
	cout<<"The Array in descending order is : "<<endl;
	print_array(arr,sz);
	return 0;
}
