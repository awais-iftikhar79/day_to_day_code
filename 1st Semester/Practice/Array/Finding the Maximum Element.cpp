#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter size of array"<<endl;
	cin>>size;
	int num[size];
	for(int i=0;i<size;i++){
		cout<<"Enter value at index "<<i<<endl;
		cin>>num[i];
	}
	int max=num[0];
	for(int i=0;i<size;i++){
		if(num[i]>max){
			max=num[i];
		}
	}
	cout<<"Max number is "<<max;
	return 0;
}
