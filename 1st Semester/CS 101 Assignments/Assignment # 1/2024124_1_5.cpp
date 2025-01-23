#include<iostream>
using namespace std;
int main(){
    float distance,petrol,cd70,cg125;
	cout<<"Enter distance in kilometers"<<endl;
	cin>>distance;
	if(distance>0){
	
    cd70=distance*0.01992031873;
    cout<<"Required petrol for CD70 is : "<<cd70<<" liter"<<endl;
    cg125=distance*0.02469135802;
	cout<<"Required petrol for CG125 is : "<<cg125<<" liter"<<endl;
    }else{
    	cout<<"I think you don't have any bike or car ";
	}
	return 0;
	
}
