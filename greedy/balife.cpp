#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ;i< n;i++){
		cin>>a[i];
	}
	// if(n%2 != 0){
	// 	cout<<-1<<endl;
	// 	return 0;
	// }

	int csum[n];
	csum[0] = a[0];

	for(int i = 1;i<n;i++){
		csum[i] = csum[i-1] + a[i];
	}

	// cout<<csum[n-1]<<endl;

	int to = csum[n-1]/n;
	if( csum[n-1]%n != 0){
		cout<<-1<<endl;
		return 0;
	}
	int m = INT_MIN;
	int diff;
	for(int i =0 ;i < n ;i++){
		diff = abs(csum[i] - to*(i+1));
		m = max(diff,m);
	}
	cout<<m<<endl;

	return 0;
}