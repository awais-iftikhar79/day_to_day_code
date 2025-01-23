#include<iostream>
using namespace std;
int main(){
	int n,count=0;
	cout<<"Enter number"<<endl;
	cin>>n;
	char alphabet='a';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			count++;
			if(count%2==0){
				cout<<char(alphabet-32);
			}else{
				cout<<alphabet;
			}
			alphabet++;
		}
		cout<<endl;
	}
	return 0;
}
