#include<iostream>
using namespace std;
void menu_of_options(){
	cout<<"Please select one of the following operation do you want to perform"<<endl;
	cout<<"1.Identify type of matrix"<<endl;
	cout<<"2.Identify order of matrix"<<endl;
	cout<<"3.Find transpose of a matrix"<<endl;
	cout<<"4.Find adjoint of matrix"<<endl;
	cout<<"5.Find inverse of matrix"<<endl;
	cout<<"6.Multiply two matrices"<<endl;
}
void check_matrix_type(int matrix[3][3],int rows,int col){
	if(rows!=col){
		cout<<"The matrix is not square"<<endl;
	}
	bool is_scalar=1,is_identity=1,is_diagonal=1,is_zero=1;
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			if(i==j && matrix[i][j]!=matrix[0][0]) is_scalar=0;
			if(i==j && matrix[i][j]!=1) is_identity=0;
			if(i!=j && matrix[i][j]!=0) is_diagonal=0;
			if(matrix[i][j]!=0) is_zero=0;
			}
		}
		if(is_diagonal){
			cout<<"The matrix is diagonal"<<endl;
		}
		if(is_identity){
			cout<<"The matrix is identity"<<endl;
		}
		if(is_scalar){
			cout<<"The matrix is scalar"<<endl;
		}
		if(is_zero){
			cout<<"The matrix is zero"<<endl;
		}
}
void order_of_matrix(int marix[3][3],int rows,int col){
	cout<<"order of matrix is "<<rows<<" x "<<col<<endl;
}
void transpose_of_matrix(int matrix[3][3],int rows,int col){
	cout<<"Transpose of matrix is : "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			cout<<matrix[j][i]<<" ";
		}
		cout<<endl;
	}
}
float adjoint_of_matrix(int matrix[3][3],float adjoint[3][3],int rows,int col){
	if(rows!=col){
		cout<<"Adjoint is not possible"<<endl;
		return 2;
	}
	if(rows==2 && col==2){
		int replace=matrix[0][0];
		matrix[0][0]=matrix[1][1];
		matrix[1][1]=replace;
		matrix[0][1] *= -1;
		matrix[1][0] *= -1;
		cout<<"Adjoint of matrix is : "<<endl;
		for(int i=0;i<rows;i++){
			for(int j=0;j<col;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		return 1 ;
	}
	int temp[3][3];
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			int minor[2][2];
			int x=0,y=0;
			for(int m=0;m<rows;m++){
				for(int n=0;n<col;n++){
					if(m!=i && n!=j){
						 minor[x][y]=matrix[m][n];
						y++;
						if(y==0){
							y=0;
							x++;
						}
					}
				}
			}
			int det_minor=minor[0][0]*minor[1][1]-minor[0][1]*minor[1][0];
			temp[i][j]=((i+j)%2==0?1:-1)*det_minor;
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			adjoint[i][j]=temp[j][i];
		}
	}
	cout<<"Adjoint of matrix is :"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			cout<<adjoint[i][j]<<" ";
		}
		cout<<endl;
	}
}
int calculate_det_2x2(int matrix[2][2]){
	int det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
	return det;
}
int inverse_of_matrix(int matrix[3][3],float inverse[3][3],int rows,int col){
	if(rows!=col){
		cout<<"Inverse not exist!"<<endl;
		return 1;
	}
	if(rows==2 && col==2){
	int det2x2=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
	if(det2x2==0){
		cout<<"Inverse does not exist.Matrix is singular!"<<endl;
		return 1;
	}
	float adjoint[2][2];
       adjoint[0][0] = matrix[1][1];
       adjoint[0][1] = -matrix[0][1];
       adjoint[1][0] = -matrix[1][0];
       adjoint[1][1] = matrix[0][0];
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			inverse[i][j]=(adjoint[i][j])/det2x2;
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
		cout<<inverse[i][j]<<" ";
		}
		cout<<endl;
	}
	}else{
	int	minor1[2][2]={{matrix[1][1],matrix[1][2]},{matrix[2][1],matrix[2][2]}};
	int	minor2[2][2]={{matrix[1][0],matrix[1][2]},{matrix[2][0],matrix[2][2]}};
	int	minor3[2][2]={{matrix[1][0],matrix[1][1]},{matrix[2][0],matrix[2][1]}};
	int det1=calculate_det_2x2(minor1);
	int det2=calculate_det_2x2(minor2);
	int det3=calculate_det_2x2(minor3);
	int determinant=matrix[0][0]*det1-matrix[0][1]*det2+matrix[0][2]*det3;
	if(determinant==0){
		cout<<"Invers doest not exist.Matrix is singular!"<<endl;
		return 1;
	}
	float adjoint[3][3];
	adjoint_of_matrix(matrix,adjoint,rows,col);
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			inverse[i][j]=(adjoint[i][j])/determinant;
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
		cout<<inverse[i][j]<<" ";
		}
		cout<<endl;
	}
}
}
void multipliacation(int matrix1[3][3],int matrix2[3][3],int result[3][3],int row1,int row2,int col1,int col2){
	if(col1!=row2){
		cout<<"Multiplication is not possible"<<endl;
		return;
	}
	 for(int i=0;i<row1;i++){
	 	for(int j=0;j<col2;j++){
	 		result[i][j]=0;
		 }
	 }
    for(int i=0;i<row1;i++){
    	for(int j=0;j<col2;j++){
    		for(int k=0;k<col1;k++){
    			result[i][j] += matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	for(int i=0;i<row1;i++){
		for(int j=0;j<col2;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}		
	}

int main(){
	int rows1,col1,rows2,col2,chioce;
	char option;
	do{
	do{
	menu_of_options();
	cout<<"Enter your choice"<<endl;
	cin>>chioce;
	switch(chioce){
		case 1:
			cout<<"Enter number of rows (2 or 3)"<<endl;
			cin>>rows1;
			cout<<"Enter number of coloum (2 or 3)"<<endl;
			cin>>col1;
			if(rows1!=2 && rows1!=3 || col1!=2 && col1!=3){
			cout<<"Only 2x2 or 3x3 matrices are supported"<<endl;
			return 1;
				}
			int matrix[3][3];
			cout<<"Enter elements in matrix of order "<<rows1<<" x "<<col1<<endl;
			for(int i=0;i<rows1;i++){
				for(int j=0;j<col1;j++){
				cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
				cin>>matrix[i][j];
					}
				}
			cout<<"The elements you enter in matrix are "<<endl;
			for(int i=0;i<rows1;i++){
				for(int j=0;j<col1;j++){
				cout<<matrix[i][j]<<" ";
					}
			cout<<endl;
				}
			check_matrix_type(matrix,rows1,col1);
			break;	
		case 2:
				cout<<"Enter number of rows (2 or 3)"<<endl;
				cin>>rows1;
				cout<<"Enter number of coloum (2 or 3)"<<endl;
				cin>>col1;
				order_of_matrix(matrix,rows1,col1);
				break;		
		case 3:
				cout<<"Enter number of rows (2 or 3)"<<endl;
				cin>>rows1;
				cout<<"Enter number of coloum (2 or 3)"<<endl;
				cin>>col1;
				if(rows1!=2 && rows1!=3 || col1!=2 && col1!=3){
					cout<<"Only 2x2 or 3x3 matrices are supported"<<endl;
					return 1;
					}
				cout<<"Enter elements in matrix of order "<<rows1<<" x "<<col1<<endl;
				for(int i=0;i<rows1;i++){
					for(int j=0;j<col1;j++){
						cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
						cin>>matrix[i][j];
							}
						}
				transpose_of_matrix(matrix,rows1,col1);
				break;
		case 4: 	
				cout<<"Enter number of rows (2 or 3)"<<endl;
				cin>>rows1;
				cout<<"Enter number of coloum (2 or 3)"<<endl;
				cin>>col1;
				if(rows1!=2 && rows1!=3 || col1!=2 && col1!=3){
					cout<<"Only 2x2 or 3x3 matrices are supported"<<endl;
					return 1;
					}
				cout<<"Enter elements in matrix of order "<<rows1<<" x "<<col1<<endl;
				for(int i=0;i<rows1;i++){
					for(int j=0;j<col1;j++){
						cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
						cin>>matrix[i][j];
							}
						}
				float adjoint[3][3];		
				adjoint_of_matrix(matrix,adjoint,rows1,col1);		
				break;
		case 5:
		 		cout<<"Enter number of rows (2 or 3)"<<endl;
				cin>>rows1;
				cout<<"Enter number of coloum (2 or 3)"<<endl;
				cin>>col1;
				if(rows1!=2 && rows1!=3 || col1!=2 && col1!=3){
					cout<<"Only 2x2 or 3x3 matrices are supported"<<endl;
					return 1;
					}
				cout<<"Enter elements in matrix of order "<<rows1<<" x "<<col1<<endl;
				for(int i=0;i<rows1;i++){
					for(int j=0;j<col1;j++){
						cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
						cin>>matrix[i][j];
							}
						}
				float inverse[3][3];
				inverse_of_matrix(matrix,inverse,rows1,col1);	
				break;
		case 6:
				int matrix_1[3][3],matrix_2[3][3];
				cout<<"Enter number of rows for matrix 1 (2 or 3)"<<endl;
				cin>>rows1;
				cout<<"Enter number of coloum for matrix 1(2 or 3)"<<endl;
				cin>>col1;
				cout<<"Enter elements in matrix of order "<<rows1<<" x "<<col1<<endl;
				for(int i=0;i<rows1;i++){
					for(int j=0;j<col1;j++){
						cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
						cin>>matrix_1[i][j];
							}
						}
				cout<<"Enter number of rows for matrix 2(2 or 3)"<<endl;
				cin>>rows2;
				cout<<"Enter number of coloum for matrix 2 (2 or 3)"<<endl;
				cin>>col2;
				cout<<"Enter elements in matrix of order "<<rows2<<" x "<<col2<<endl;
				for(int i=0;i<rows2;i++){
					for(int j=0;j<col2;j++){
						cout<<"Enter element at ["<<i<<"]["<<j<<"]"<<endl;
						cin>>matrix_2[i][j];
							}
						}
				int result[3][3];
				multipliacation(matrix_1,matrix_2,result,rows1,rows2,col1,col2);
				break;
		default:							
			cout<<"Invalid option !"<<endl;
		}
	}while(chioce<1 || chioce>6);
	cout<<"Do you want to perform more calculaations (Y/N) ?"<<endl;
		cin>>option;
	}while(option=='Y' || option=='y');
	cout<<"Thanks for visting!"<<endl;
	return 0;
}
