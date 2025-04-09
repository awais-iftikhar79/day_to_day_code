#include<iostream>
using namespace std;
int main(){
	int arr[3][4];
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
		int Max_Sum_Row=INT_MIN;
	for(int i=0;i<3;i++){
	
		int Row_Sum=0;
		for(int j=0;j<4;j++){
			Row_Sum += arr[i][j];
		}
		Max_Sum_Row=max(Max_Sum_Row,Row_Sum);
	}
	cout<<"The max sum of row is "<<Max_Sum_Row;
	
	return 0;
}
