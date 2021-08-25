#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long int,long long int> p1, pair<long long int,long long int> p2){
	return p1.first < p2.first;
}

bool mycompare(pair<long long int,long long int> p1, pair<long long int,long long int> p2){
	return p1.second < p2.second;
}

int main(){

	long long int n;
	cin>>n;
	long long int a[n];
	vector<pair<long long int,long long int>> v;
	long long int p,q;
	
	for(long long int i=0 ;i < n ;i++){
		cin>>p;
		cin>>q;
		v.push_back(make_pair(p,q));
	}

	long long int sx = 0;
	long long int sy = 0;

	vector<long long int> dx;
	vector<long long int> dy;

	sort(v.begin(),v.end(),compare);
	long long int m = INT_MIN;
	for(long long int i = 0;i<n;i++){
		dx.push_back(v[i].first - sx - 1);
		m = max(m, v[i].first - sx - 1);
		sx = v[i].first;
	}

	sort(v.begin(),v.end(),mycompare);
	long long int l = INT_MIN;
	for(long long int i = 0;i<n;i++){
		dy.push_back(v[i].second - sy - 1);
		l = max(l, v[i].second - sy - 1);
		sy = v[i].second;
	}		

	long long int ans = m*l;
	cout<<ans<<endl;

	return 0;
}