#include<iostream>
using namespace std;
int main(){
	int n=5;
	for(int i=0;i<5;i++){
		for(int s=5-i;s>0;s--){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			cout<<"*";
		}
		for(int k=0;k<=(2*i-1);k++){
			if(i<4){
				cout<<" ";
			}
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
