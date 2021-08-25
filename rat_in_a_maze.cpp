#include<bits/stdc++.h>
using namespace std;

bool rat_in_a_maze(char maze[10][10], int sol[][10] , int i, int j ,int m , int n)
{
	//base case
	if(i == m && j == n)
	{
		sol[m][n] = 1;
		//print the path
		for(int i=0;i<=m;i++)
		{
			for(int j =0;j<=n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}


	if( i > m || j > n)
		return false;

	if(maze[i][j] == 'X')
		return false;

	
	//assume sol exist through current cell
	sol[i][j] = 1;

	//rec case
	int rightsuccess = rat_in_a_maze(maze, sol , i, j+1, m, n);
	int leftsuccess = rat_in_a_maze(maze, sol, i+1, j ,m, n);

	//backtracking
	sol[i][j] = 0;


	if(leftsuccess || rightsuccess)
		return true;
	return false;
}



int main()
{

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};
	int sol[10][10] = {0};
	int m=4;
	int n = 4;

	bool ans= rat_in_a_maze(maze , sol, 0, 0 ,m-1, n-1);

	if(!ans)
		 cout<<"Path does not exist!!"<<endl;
	

	return 0;
}