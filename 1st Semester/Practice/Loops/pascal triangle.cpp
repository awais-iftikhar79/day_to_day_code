#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter number "<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		int co_effi=1;
		for(int s=n-i;s>0;s--){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<co_effi<<" " ;
			co_effi =	co_effi *(i-j)/j;
		}
		cout<<endl;
	}
	return 0;
}
