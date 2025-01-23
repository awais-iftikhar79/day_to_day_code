#include<iostream>
using namespace std;
int main(){
	int num;
	while(true){
		cout<<"Enter number "<<endl;
		cin>>num;
		
		if(num==0){
			cout<<"end program"<<endl;
			break;
		}
		if(num%2==0){
			cout<<"Number is even "<<endl;
		}else{
			cout<<"Number is odd"<<endl;
		}	
		
	}
  

	return 0;
}
