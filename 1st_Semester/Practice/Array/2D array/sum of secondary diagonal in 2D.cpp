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
	int Sec_Diagonal_Sum=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(j==4-1-i){
		Sec_Diagonal_Sum += arr[i][j];		
			}
		}
	}
	cout<<"The sum of secondary diagonal is "<<Sec_Diagonal_Sum;
	return 0;
}
