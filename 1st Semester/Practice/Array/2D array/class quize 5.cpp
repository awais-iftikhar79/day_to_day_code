#include<iostream>
using namespace std;
int main(){
	int arr[3][4]={{1,2,3,5},{5,6,7,8},{9,10,11,12}};
	for(int i=0;i<3;i++){
		float sum=0,average=0;
		for(int j=0;j<4;j++){
			sum += arr[i][j];
		}
		average=(sum)/4;
		cout<<"CGPA average of student "<<i+1<<" = "<<average;
		cout<<endl;
	}
	return 0;
}
