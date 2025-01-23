#include<iostream>
using namespace std; 
int main(){
	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int result[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result[j][i]=arr[i][j];
		}
	}
	cout<<"Original Matrix is \n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Transpose of matrix is \n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
