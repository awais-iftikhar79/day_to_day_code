#include<iostream>
using namespace std;
int main(){
	int arr[5]={34,25,32,56,78};
	int Max_Num=INT_MIN;
	for(int i=0;i<5;i++){
	Max_Num=max(Max_Num,arr[i]);
    }
    cout<<"The max number in array is "<<Max_Num;
	return 0;
}
