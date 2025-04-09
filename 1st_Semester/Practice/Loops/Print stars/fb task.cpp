#include<iostream>
using namespace std;
 int main(){
 	int n=5;
 	for(int i=1;i<=4;i++){
 		for(int s=5-i;s>0;s--){
 			cout<<" ";
		 }
 		for(int j=1;j<=i;j++){
 			cout<<"*";
		 }
		 cout<<endl;
	 }

	 for(int i=5;i>0;i--){
	 	for(int s=5-i;s>0;s--){
	 		cout<<" ";
		 }
		 for(int j=1;j<=i;j++){
		 	cout<<"*";
		 }
		 cout<<endl;
	 }
 	
 	return 0;
}
