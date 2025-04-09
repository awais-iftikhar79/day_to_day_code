#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream file_to_write("student.txt",ios::app);
	if(file_to_write.is_open()){
	//	file_to_write<<"Hello, I am writng data of students in file\n";
		file_to_write<<"Name  :  Saad Ismail    ,  Age : 19\n";
		file_to_write<<"Name  :  Muhammad Ahmad        ,  Age : 20\n";
		cout<<"Data has been uploaded sucessfully!"<<endl;
		file_to_write.close();
	}else{
		cout<<"Unable to write file without opening\n";
	}
	return 0;
}

