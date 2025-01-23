 #include<iostream>
using namespace std;
void bubble_sort_recursion(int arr[],int n){
	if(n==1){
		return;
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	return bubble_sort_recursion(arr,n-1);
}
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={9,3,7,2,5};
	int sz=sizeof(arr)/sizeof(int);
	bubble_sort_recursion(arr,sz);
	cout<<"The array in ascending order is : ";
	print_array(arr,sz);
	return 0;
}
