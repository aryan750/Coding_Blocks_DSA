#include<bits/stdc++.h>
using namespace std;

int coin_change(int n , int *coins ,int T, int dp[] ){

	//base case
	if(n == 0){
		return 0;
	}

	//lookup
	if(dp[n] != 0 ){
		return dp[n];
	}

	//rec case
	int ans = INT_MAX;
	for(int i = 0;i<T;i++){
		if(n - coins[i] >= 0){
			int subprob = coin_change(n-coins[i],coins,T,dp);
			ans = min(ans, subprob + 1);
		}
	}
	dp[n] = ans;
	return dp[n];
}

//bottom Up
int coin_change_BU(int N, int *coins, int T){

	int dp[100] = {0};

	for(int i = 1;i <= N;i++){
		dp[i] = INT_MAX;
		for(int j = 0 ; j < T;j++){
			if(i-coins[j]>=0){
				int subprob = dp[i-coins[j]];
				dp[i] = min(dp[i],subprob+1);
			}
		}
	}
	return dp[N];
}


int main(){

	int N = 15;
	int coins[] = {1,7,10};
	int dp[100] = {0};
	int T = sizeof(coins)/sizeof(int);

	// cout<<coin_change(N,coins,T,dp)<<endl; 
	cout<<coin_change_BU(N,coins,T)<<endl; 



	return 0;
}