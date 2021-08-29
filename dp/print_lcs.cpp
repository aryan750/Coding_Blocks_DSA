#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000] = {0};


void lcs(string s1, string s2){
	
	int p = s1.length();
	int q = s2.length();

	for(int i = 0; i<= p ;i++){
		for(int j = 0 ;j <= q;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}

			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}

	int d = dp[p][q];
	char ch[d];
	ch[d] = '\0';

	int ip = p;
	int jp = q;
	int pf = d;

	while(ip > 0 && jp > 0){
		if(s1[ip-1] == s2[jp-1]){
			ch[pf-1] = s1[ip-1];
			pf--;
			ip--;
			jp--;
		}
		else if(dp[ip-1][jp] > dp[ip][jp-1]){
			ip--;
		}
		else{
			jp--;
		}
	}

	for(int i = 0 ;i < d;i++){
		cout<<ch[i];
	}


}


int main(){

	string s1;
	string s2;

	cin>>s1;
	cin>>s2;

	int n1 = s1.size();
	int n2 = s2.size();

	
	lcs(s1,s2);
	cout<<endl;



	return 0;
}