#include<bits/stdc++.h>
using namespace std;

//top down
int profits(int wines[], int i, int j, int y, int dp[][100]){
	//base case
	if(i > j){
		return 0;
	}

	if(dp[i][j]	!= 0 ){
		return dp[i][j];
	}
	//rec case
	int op1 = wines[i]*y + profits(wines,i+1,j,y+1,dp);
	int op2 = wines[j]*y + profits(wines,i,j-1,y+1,dp);

	return dp[i][j] = max(op1,op2);
}

//bottom up
// int profits_BU(int wines[],int i ,int j, int y)
// {
	
// }


int main(){

	int wines[] = {2,3,5,1,4};
	int n = sizeof(wines)/sizeof(int);
	int dp[100][100] = {0};
	int y = 1;
	cout<<profits(wines,0,n-1,y,dp)<<endl;

	return 0;
}