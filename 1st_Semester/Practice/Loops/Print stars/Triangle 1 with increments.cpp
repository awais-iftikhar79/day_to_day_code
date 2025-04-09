#include<iostream>
using namespace std;
int main(){
	int n,x=1;
	cout<<"Enter a number"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<x++;
		}
		cout<<endl;
	}
	return 0;
}
