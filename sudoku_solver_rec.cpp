#include<bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9] , int i, int j, int n ,int no)
{
	int rt = sqrt(n);
	//we will check in the row , column and in the same grid
	int sx= (i/rt)*rt;
	int sy= (j/rt)*rt;

	for(int x=0;x<n;x++)
	{
		//rown and column
		if(mat[x][j] == no || mat[i][x] == no)
		{
			return false;
		}
	}

	for(int x=sx;x<sx+3;sx++)
	{
		for(int y=sy;y<sy+3;sy++)
		{
			if(mat[x][y] == no)
				return false;
		}
	}
	return true;
}


bool sudoku(int mat[][9] , int i, int j, int n)
{

	//base case
	if(i == n)
	{
		//print the sol
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}	

	if(j == n)
	{
		return sudoku(mat,i+1,0,n);
	}

	//skip where exist a element
	if(mat[i][j] != 0)
	{
		return sudoku(mat, i, j+1, 0);
	}


	//rec case
	for(int no =1;no <=n;no++)
	{
		if(canPlace(mat,i,j,n,no))
		{
			//assuming it is a right no
			mat[i][j] = no;
			bool couldwesolve = sudoku(mat, i,j+1,n);
			if(couldwesolve)
				return true;
		}
	}
	//backtrack
	mat[i][j] = 0;
	return false;
}


int main()
{
	int mat[9][9] = {
		//enter the input in 9 rows and 9 col
	}

	sudoku(mat,0,0,9);

	return 0;
}