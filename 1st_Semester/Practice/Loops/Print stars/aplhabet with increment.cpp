#include<iostream>
using namespace std;
int main(){
	int n;
	char alphabet ='a';
	cout<<"Enter a number"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<alphabet++;
		}
		cout<<endl;
	}
	return 0;
}
