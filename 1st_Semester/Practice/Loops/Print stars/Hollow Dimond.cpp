#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter a number"<<endl;
cin>>n;
for(int i=0;i<n;i++){
	for(int j=0;j<(2*n);j++){
		if(i+j<=n-1){   //uper left triangle
			cout<<"*";
		}else{
			cout<<" ";
		}
		if(i+n<=j){   // upper right- triangle
			cout<<"*";
		}else{
			cout<<" ";
		}
	}
	cout<<endl;
}
for(int i=0;i<n;i++){
	for(int j=0;j<(2*n);j++){
		if(i>=j){    // bottom left triangle
			cout<<"*";
		}else{
			cout<<" ";
		}
		if(i>=(2*n-1)-j){   // bottom right triangle
			cout<<"*";
		}else{
			cout<<" ";
		}
	}
	cout<<endl;
}
    return 0;
}

