#include<iostream>
using namespace std;
void reverse_pointer(int* arr,int s,int e){
		if(s>=e){
			return;
		}
		swap(*(arr+s),*(arr+e));
	   reverse_pointer(arr,s+1,e-1);
	}
int main(){
	
	int arr[]={3,4,5,6,7,8};
	cout<<"Original array is ";
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int n=sizeof(arr)/sizeof(int);
	reverse_pointer(arr,0,n-1);

	cout<<"Reverse array is : ";
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

