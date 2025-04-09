#include<iostream>
using namespace std;
int main(){
	int start =10,row=4;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=i;j++){
			cout<<(start+j);
		    if(j<i){
			cout<<"-";
	     	} 
		}
		cout<<endl;
	}
	
	return 0;
}
