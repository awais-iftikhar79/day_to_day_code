#include<iostream>
using namespace std;
void count_by_pointer(int* arr,int n){
	int even=0,odd=0;
	for(int i=0;i<n;i++){
		if((*(arr+i))%2==0){
			even++;
		}else{
			odd++;
		}
	}
	cout<<"Even numbers are : "<<even<<endl;
	cout<<"Odd numbers are : "<<odd<<endl; 
}
int main(){
	int n;
	cout<<"Enter size of an array "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements in an array "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Original array is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	count_by_pointer(arr,n);
	return 0;
}
