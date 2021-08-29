#include<bits/stdc++.h>
using namespace std;

// int dp[1000][1000][1000];


int lcs(string s1, string s2,string s3){

	int p = s1.length();
	int q = s2.length();
	int r = s3.length();

	int dp[p+1][q+1][r+1];
	memset(dp,0,sizeof(dp));

	for(int i = 0; i<= p ;i++){
		for(int j = 0 ;j <= q;j++){
			for(int k = 0 ; k <= r;k++){
				if(i == 0 || j == 0 || k == 0){
					dp[i][j][k] = 0;
				}
				else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]){
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				}
				else{
					dp[i][j][k] = max(dp[i-1][j][k] , max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[p][q][r];
}



int main(){

	string s1;
	string s2;
	string s3;

	cin>>s1;
	cin>>s2;
	cin>>s3;
	
	cout<<lcs(s1,s2,s3); 
	cout<<endl;
	return 0;
}