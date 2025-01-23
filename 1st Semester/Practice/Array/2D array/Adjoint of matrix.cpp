#include<iostream>
using namespace std;
int main(){
	int arr[2][2]={{1,2},{3,4}};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(i+j==1){
				arr[i][j] *= -1;
			}
		}
	}
	int temp=arr[0][0];
	arr[0][0]=arr[1][1];
	arr[1][1]=temp;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
