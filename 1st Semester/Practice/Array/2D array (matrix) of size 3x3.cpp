#include<iostream>
using namespace std;
int main(){
	int matrix[3][3];
	cout<<"Enter 9 vlaues for matrix 3x3 \n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<"Enter values at indeces ["<<i<<"]["<<j<<"]";
			cin>>matrix[i][j];
		}
	}
	cout<<"The matrix of 3x3 is :\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
