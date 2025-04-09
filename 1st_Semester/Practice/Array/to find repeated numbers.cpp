#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Ente size of an array"<<endl;
	cin>>size;
	int array[size];
	for(int i=0;i<size;i++){
		cout<<"Enter values at index "<<i<<endl;
		cin>>array[i];
	}
	cout<<"Numbers in array are : ";
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
 	cout<<"Repeated numbers are : ";
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]==array[j]){
				cout<<array[j]<<" ";
			}
		}
	}
	return 0;
}
