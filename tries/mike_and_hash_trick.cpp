#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;

bool compare(int a, int b){
	return m[a] < m[b];
}

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i= 0 ;i<n;i++){
		cin>>a[i];
	}

	vector<int> ans;
	int val = 0;
	for(int i=0;i<n;i++){
		if(m.count(a[i])){
			m[a[i]] = ++val;
		}
		else{
			m[a[i]] = ++val;
			ans.push_back(a[i]);
		}	
	}

	sort(ans.begin(), ans.end(),compare);
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}