#include<bits/stdc++.h>
using namespace std;

int ladder_topdown(int n, int k, int dp[]){
	//base case
	if(n == 0){
		return 1;
	}
	//lookup
	if(dp[n] != 0){
		return dp[n];
	}

	int ans = 0;
	for(int i = 1;i <=k;i++){
		if(n-i >= 0){
			ans += ladder_topdown(n-i,k,dp);
		}
	}
	return dp[n] = ans;
}


//bottom up
int ladders_bottomUp(int n ,int k)
{
	int dp[100] = {0};
	dp[0] = 1;

	for(int i = 1; i <= n; i++){
		dp[i] = 0;
		for(int j = 1 ; j <= k; j++){
			if(i - j >= 0){
				dp[i] += dp[i-j];
			}
		}
	}
	//see the bottom up
	for(int i = 0 ;i <= n ;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[n];
}

int ladder_optimed(int n ,int k){

	int dp[100] = {0};

	dp[0] = dp[1] = 1;

	for(int i =2 ; i <= k;i++){
		dp[i] = 2*dp[i-1];
	}
	for(int i = k+1;i <= n;i++){
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}

	//print
	for(int i = 0 ; i <  n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[n];
}



int main(){

	int n,k;
	cin>>n>>k;

	int dp[100] = {0};
	cout<<ladder_topdown(n,k,dp)<<endl;

	cout<<ladders_bottomUp(n,k)<<endl;
	cout<<ladder_optimed(n,k)<<endl;
	return 0;
}