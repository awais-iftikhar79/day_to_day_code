#include<iostream>
using namespace std;
int checkprime(int a){
	int check=0;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			check++;
		}
	}if(check==2){
		cout<<"The number "<<a<< " is prime";
	}else{
		cout<<"The number "<<a<< "is not prime";
	}
}
int main(){
	int num,findprime;
	cout<<"Enter num"<<endl;
	cin>>num;
	if(num>0){
	findprime=checkprime(num);
    }else {
    	cout <<"Invalid data";
	}
	return 0;
}
