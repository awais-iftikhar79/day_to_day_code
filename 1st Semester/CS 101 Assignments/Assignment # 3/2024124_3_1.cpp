#include<iostream>
#include<string>
using namespace std;
void display(string family[2][10]){
	cout<<"Names \t:";
	for(int i=0;i<10;i++){
	
		if(!family[0][i].empty()){
			cout<<family[0][i]<<" ";
		}
	}
	cout<<endl;
	cout<<"Status \t:";
	for(int i=0;i<10;i++){
		if(!family[1][i].empty()){
			cout<<" "<<family[1][i]<<"      ";
		}
	}
	
}
void Swap(string family[2][10],int i,int j){
	swap(family[0][i],family[0][j]);
	swap(family[1][i],family[1][j]);
}
void selection_sorting(string family[2][10]){
	for(int i=0;i<9;i++){
		int min_index=i;
		for(int j=i+1;j<10;j++){
			if(family[1][j]>family[1][min_index]){
				min_index=j;
			}
			}
			if(min_index!=i){
			Swap(family,i,min_index);
		}
	}
}
void trnasfer_non_covid(string Amna_family[2][10],string Iffat_Family[2][10],int count){
	for(int i=0;i<10;i++){
	if(Amna_family[1][i]=="N"){
		Iffat_Family[0][count]=Amna_family[0][i];
		Iffat_Family[1][count]=Amna_family[1][i];
		count++;
	}
}
}
int main(){
	string Amna_family[2][10]={{"Amna","Father","Mother","Sister","Brother 1","Brother 2","GrandFather","GrandMother","Uncle","Aunt"},{"P","N","P","N","P","P","N","N","N","N"}};
	cout<<"Original Family details "<<endl;
	display(Amna_family);
	cout<<endl<<"Sorted Family details is : "<<endl;
	selection_sorting(Amna_family);
	display(Amna_family);
	string Iffat_Family[2][10];
	int non_covid_count=0;
	trnasfer_non_covid(Amna_family,Iffat_Family,non_covid_count);
	cout<<endl<<"Iffat's family now"<<endl;
	display(Iffat_Family);
	return 0;
}
