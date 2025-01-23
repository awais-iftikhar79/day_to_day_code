#include<iostream>
using namespace std ;
int main(){
	int arr[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	int Diagonal_Sum=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==j){
		Diagonal_Sum += arr[i][j];		
			}
		}
	}
	cout<<"The sum of primary diagonal is "<<Diagonal_Sum;
	return 0;
}
