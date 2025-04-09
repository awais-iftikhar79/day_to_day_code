#include<iostream>
using namespace std;
	
bool chcek_prime(int a){
	int check=0;
	for(int i=1;i<=a;i++){	
		if(a%i==0){
	 		check++;
		}
	}
	return check==2;
}
int main(){
	int start,end;
    cout<<"Enter first number"<<endl;
	cin>>start;
	cout<<"Enter second number"<<endl;
	cin>>end;
	for(int i=start;i<=end;i++){
	    if(chcek_prime(i)){
	    	cout<<i<<" ";
		}
	}
	
	return 0;
}
