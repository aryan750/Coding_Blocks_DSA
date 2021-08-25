#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int k = 1000000007;

int main(){

	ll n;
	cin>>n;
	ll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}	
	ll ans = 0;
	unordered_set<ll> m;
	int j =0;

	for(int i = 0;i<n;i++){
		while(j < n && m.find(arr[j]) == m.end()){
			m.insert(arr[j]);
			j++;
		}
		ans += (((j-i)*(j-i+1))/2)%k;
		ans = ans%k;
		m.erase(arr[i]);
	}
	int t = ans %k;
	cout<<t<<endl;
	return 0;
}