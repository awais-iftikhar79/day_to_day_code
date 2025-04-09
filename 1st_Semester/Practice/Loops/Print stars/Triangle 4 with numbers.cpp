#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter a number "<<endl;
	cin>>num;
	for(int i=num;i>=1;i--){
		for(int s=num-i;s>0;s--){
		cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<(num-i+1);
		}
		cout<<endl;
	}
	return 0;
}
