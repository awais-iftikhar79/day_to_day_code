#include<iostream>
using namespace std; 
int main(){
	int arr[2][2]={{1,2},{3,4}};
	int result[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			result[j][i]=arr[i][j];
		}
	}
	cout<<"Transpose of matrix is \n";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
