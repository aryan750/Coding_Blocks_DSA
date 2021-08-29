#include<bits/stdc++.h>
using namespace std;

void count_binary(long long int *dp){
	
	dp[1] = 2;
	dp[2] = 3;
	for(int i = 3 ;i < 1000;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return;
}


int main(){
	int t;
	cin>>t;
	long long int dp[1005];
	count_binary(dp);
		
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}