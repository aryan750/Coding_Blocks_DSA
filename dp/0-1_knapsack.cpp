#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int knapsack(int *size, int *value, int n, int s){

	if(n == 0 || s == 0){
		return 0;
	}

	if(dp[n][s] != -1){
		return dp[n][s];
	}

	int inc = 0;
	int exc = 0;
	int ans = 0;

	if(size[n-1] <= s){
		inc = value[n-1] + knapsack(size,value,n-1,s-size[n-1]);
	}
	exc = knapsack(size,value,n-1,s);
	ans = max(inc,exc);
	dp[n][s] = ans;
	return ans;
}

int main(){

	int s,n;
	cin>>n>>s;
	int size[1005];
	int value[1005];
	for(int i = 0 ;i< n;i++){
		cin>>size[i];
	}
	
	for(int i = 0 ;i< n;i++){
		cin>>value[i];
	}
	memset(dp,-1,sizeof(dp));

	cout<<knapsack(size,value,n,s)<<endl;


	return 0;
}