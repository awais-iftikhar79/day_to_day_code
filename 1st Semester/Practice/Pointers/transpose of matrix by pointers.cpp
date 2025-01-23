#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter size of an array "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout <<"Elements in array are ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	int Max_Num=INT_MIN;
	for(int i=0;i<n;i++){
	Max_Num=max(Max_Num,*(arr+i));
    }
    cout<<"The greatest element in your array is : "<<Max_Num;
	return 0;
}
