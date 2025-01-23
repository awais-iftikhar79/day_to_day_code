#include<iostream>
using namespace std;
int main(){
	int score;
	cout<<"Enter your score : "<<endl;
	cin>>score;
	if((0<score)&&(score<=100)){
		if(score>=90){
			cout<<"Your Grade is A "<<endl;
		}else if(score>=80){
			cout<<"Your Grade is B "<<endl;
		}else if(score>=70){
			cout<<"Your Grade is C "<<endl;
		}else if(score>=60){
			cout<<"Your Grade is D "<<endl;
		}else{
			cout<<"Your Grade is F "<<endl;
		}
	}else{
		cout<<"Invalid data "<<endl;
	}
	return 0;
}
