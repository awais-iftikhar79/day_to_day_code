#include<iostream>
using namespace std;
int main(){
	int row,col;
	cout<<"Enter value of rows"<<endl;
	cin>>row;
	cout<<"Enter value of col "<<endl;
	cin>>col;
	int i=1,j=1;
	while(i<=row){
		j=1;
		while(j<=col){
			cout<<i<<" "<<j<<"    ";
			j++;		
		}
		cout<<endl;
		i++;
	}
	return 0;
}
