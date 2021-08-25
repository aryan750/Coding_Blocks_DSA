#include<bits/stdc++.h>
using namespace std;
int count = 0;

bool canWePlace(int mat[][11], int i, int j , int n){
	//checking for columns
	for(int row = 0 ;row <i;row++){
		if(mat[row][j] == 1){
			return false;
		}
	}

	//checking for diagonals
	//left
	int x = i ;
	int y = j;
	while(x >= 0 && y >= 0){
		if(mat[x][y] == 1){
			return false;
		}
		x--;
		y--;
	}

	x = i ;
	y = j;
	while(x >= 0 && y < n){
		if(mat[x][y] == 1){
			return false;
		}
		x--;
		y++;
	}

	//the pos is safe to place a queen
	return true;
}



bool solveNQueen(int mat[][11],int i, int n){
	if(i == n){
		// for(int x = 0;x<n;x++){
		// 	for(int y = 0 ;y < n ; y++){
		// 		if(mat[x][y] == 1){
		// 			cout<<"Q";
		// 		}
		// 		else{
		// 			cout<<"-";
		// 		}
		// 	}
		// 	cout<<endl;
		// }
		::count++;
		// cout<<endl;
		return false;
	}
	//rec case
	for(int j = 0; j < n;j++){
		if(canWePlace(mat,i,j,n)){
			mat[i][j] = 1;

			bool putNextQueen = solveNQueen(mat,i+1,n);
			if(putNextQueen == true){
				return true;
			}

			//backtrack
			mat[i][j] = 0;
		}
	}
	return false;
}




int main(){

	int n;
	cin>>n;

	int mat[11][11] = {0};
	
	solveNQueen(mat,0,n);
	cout<<::count<<endl;


	return 0;
}