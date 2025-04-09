#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter size of array"<<endl;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cout<<"Enter value at index "<<i<<endl;
		cin>>arr[i];
	}
	for(int i=0;i<size;i++){
		cout<<arr[i];
		
	}

	cout<<endl<<"-----------"<<endl;
	int s=0;
	int e=size-1;
	while(s<e){
		swap(arr[s],arr[e]);
		s++;
		e--;
	}
	for(int i=0;i<size;i++){
	cout<<arr[i];
}
	return 0;
}
