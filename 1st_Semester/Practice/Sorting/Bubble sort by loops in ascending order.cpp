#include<iostream>
using namespace std;
void bubble_sort(int arr[],int sz){
	int count;
	for(int i=0;i<sz-1;i++){
	 count==0;
		for(int j=0;j<sz-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				count++;
			}
		}
		if(count==0){
			return;
		}
	}
}
void print(int arr[],int sz){
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={6,3,8,5,11,2};
	int sz=sizeof(arr)/sizeof(int);
	bubble_sort(arr,sz);
	print(arr,sz);
	return 0;
}

