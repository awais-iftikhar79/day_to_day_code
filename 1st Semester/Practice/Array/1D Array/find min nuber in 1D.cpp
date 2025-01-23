#include<iostream>
using namespace std;
int main(){
	int arr[5]={34,25,32,56,78};
	int Min_Num=INT_MAX;
	for(int i=0;i<5;i++){
	Min_Num=min(Min_Num,arr[i]);
    }
    cout<<"The min number in array is "<<Min_Num;
	return 0;
}
