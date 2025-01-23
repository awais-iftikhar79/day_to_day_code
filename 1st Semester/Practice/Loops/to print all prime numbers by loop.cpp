#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter a number"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		int check=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				check++;
			}
		}
		if(check==2){
			cout<<i<<"  ";
		}
	}
	return 0;
}
