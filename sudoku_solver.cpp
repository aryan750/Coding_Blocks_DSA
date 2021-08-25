#include<bits/stdc++.h>
using namespace std;

bool canWePlace(int mat[][9], int i ,int j ,int n, int number){

	//for columns
	for(int x = 0;x<n;x++){
		if(mat[x][j] == number || mat[i][x] == number){
			return false;
		}
	}

	int rn = sqrt(n);
	int sx= (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x = sx ;x < sx+rn;x++){
		for(int y = sy;y < sy+rn;y++){
			if(mat[x][y] == number){
				return false;
			}
		}
	}
	return true;
}


bool sudoku_solver(int mat[][9], int i, int j, int n){

	//base case
	if(i == n){
		//print
		for(int x = 0 ;x < n;x++){
			for(int y = 0; y < n;y++){
				cout<<mat[x][y]<<" ";
			}
			cout<<endl;	
		}
		return true;
	}

	if(j == n){
		return sudoku_solver(mat,i+1,0,n);
	}

	if(mat[i][j] != 0){
		return sudoku_solver(mat,i,j+1,n);
	}

	//rec case
	for(int number = 1 ; number <= 9;number++){
		if(canWePlace(mat,i,j,n,number)){
			mat[i][j] = number;

			bool couldWeSolve = sudoku_solver(mat,i,j+1,n);
			if(couldWeSolve == true){
				return true;
			}
		}
	}
	//backtrack here
	mat[i][j] = 0;
	return false;
}



int main(){

	int n;
	cin>>n;

	int mat[9][9];
	
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ;j < n ; j++){
			cin>>mat[i][j];
		}
	}
	
	cout<<endl;
	sudoku_solver(mat,0,0,9);


	return 0;
}