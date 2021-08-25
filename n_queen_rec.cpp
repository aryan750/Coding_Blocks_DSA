#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
	//You can check for upper columns
	for(int row= 0;row <i;row++)
	{
		if(board[row][j] == 1)
			return false;
	}

	//You can check for left diagonal
	int x = i;
	int y = j;

	while(x >= 0 && y >= 0)
	{
		if(board[x][y] == 1 )
			return false;
		x--;
		y--;
	}

	//You can check for right diagonal
	x = i;
	y = j;

	while(x >= 0 && y < n)
	{
		if(board[x][y] == 1 )
			return false;
		x--;
		y++;
	}	

	//the position is now safe , col , left and right diagonal 
	return true;
}

bool solve_n_queen(int board[][10] , int i, int n)
{
	//base case
	if(i == n)
	{
		//you have successfully placed all the queens
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j] == 1)
				{
					cout<<"Q ";
				}
				else
					cout<<"_ ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}


	//rec case
	//try to put the queen in the current row and call on the remaining part 
	for(int j =0;j<n;j++)
	{
		//check if i, j the position is safe to put queen or not
		if(isSafe(board, i, j ,n)) 
		{
			//place the queen
			board[i][j] = 1;

			bool nextQueenRakhPaye = solve_n_queen(board,i+1,n);
			if(nextQueenRakhPaye)
			{
				return true;
			}
			//means i,j is not the right position --assuming is wrong
			//backtracking
			board[i][j] = 0;
		}
		
	}
	//You have trued for all positions in the current row but couldn't place 
	return false;
}


int main()
{
	
	int n ;
	cin>>n;
	int board[10][10] = {0};
	solve_n_queen(board, 0, n);

	return 0;
}