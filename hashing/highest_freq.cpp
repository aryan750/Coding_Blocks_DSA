	#include<bits/stdc++.h>
	using namespace std;

	int main(){

		long long int  n;
		cin>>n;

		map<long long int,long long int> m;
		long long int a[n];
		for(long long int i =0;i < n;i++){
			cin>>a[i];
			m[a[i]]++;
		}

		long long int maxxxy = INT_MIN;
		long long int ans = 0;
		for(map<long long int,long long int>::iterator it = m.begin();it != m.end();it++){
			if(maxxxy < it->second){
				ans = it->first;
				maxxxy = max(maxxxy,it->second);
			}
		}

		cout<<ans<<endl;


		// for(auto x : m){
		// 	for(auto p : x.second){
		// 		maxxxy = max(maxxxy,p);
		// 	}

		// }
		// cout<<maxxxy<<endl;



		return 0;
	}