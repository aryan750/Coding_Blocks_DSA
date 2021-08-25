#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int t;
	cin>>t;

	while(t--){

		long long int n;
		cin>>n;

		long long int c[n];

		for(long long int i = 0 ;i < n; i++)
		{
			cin>>c[i];
		}
		long long int l[n];

		for(long long int i = 0 ;i < n; i++)
		{
			cin>>l[i];
		}
		
		long long int min_cost = c[0];
		long long int total = min_cost*l[0];
		for(long long int i = 1 ;i < n; i++){
			if(min_cost > c[i]){
				min_cost = c[i];
				total = total + min_cost*l[i];
				continue;
			}
			else{
				total = total + min_cost*l[i];
				continue;
			}
		}
		cout<<total<<endl;
	}

	return 0;
}