#include<iostream>
using namespace std;
int main(){
	int basicsalary,houseallownce,transportallownces,medicalbills,totalsalary,nhl,nta,nmb,newsalary,differnce;
	cout<<"Enter your basic salary "<<endl;
	cin>>basicsalary;
	houseallownce=basicsalary*0.30;
	cout<<"houseallownce = "<<houseallownce<<endl;
	transportallownces=basicsalary*0.10;
	cout<<"transportallownces = "<<transportallownces<<endl;
	medicalbills=basicsalary*0.25;
	cout<<"medicalbills = "<<medicalbills<<endl;
	totalsalary=houseallownce+transportallownces+medicalbills+basicsalary;
	cout<<"Total Gross Salary is = "<<totalsalary<<endl<<endl;
	nhl=basicsalary*0.40;
	cout<<"New House Allowance = "<<nhl<<endl;
	nta=basicsalary*0.15;
	cout<<"New Transport Allowance = "<<nta<<endl;
	nmb=basicsalary*0.35;
	cout<<"New Medical Bills = "<<nmb<<endl;
	newsalary=nhl+nta+nmb+basicsalary;
	cout<<"New Total Gross Salary is = "<<newsalary<<endl<<endl;
	differnce=newsalary-totalsalary;
	cout<<"Diff b/w new and old salary is = "<<differnce<<endl;
	return 0;
}
