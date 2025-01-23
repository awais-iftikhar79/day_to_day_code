#include<iostream>
#include<cmath>
using namespace std;
int main(){
	char patteren[7]={'C','i','s','b','e','s','t'};
	for(int i=0;i<7;i++){
		for(int s=7-i;s>1;s--){
			cout<<" ";
		}
		cout<<patteren[i];
		for(int j=0;j<(2*i-1);j++){
			if(i<6){
				cout<<" ";
			}else{
				for(int i=5;i>=0;i--){
					cout<<patteren[i];
				}
					for(int i=1;i<=5;i++){
					cout<<patteren[i];
				}
			break;
			}
		}
	if(i>0){
		cout<<patteren[i]<<endl;
		}else{
		cout<<endl;
			}
	}

	return 0;
}
