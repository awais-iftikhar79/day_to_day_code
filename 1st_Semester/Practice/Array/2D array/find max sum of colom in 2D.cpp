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
	int Max_Sum_Col=INT_MIN;
	for(int j=0;j<4;j++){
		int Col_Sum=0;
		for(int i=0;i<3;i++){
			Col_Sum += arr[i][j];
		}
		Max_Sum_Col=max(Max_Sum_Col,Col_Sum);
	}
	cout<<"The max sum of col is "<<Max_Sum_Col;
	
	return 0;
}
