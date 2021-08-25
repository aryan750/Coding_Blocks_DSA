#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int n, k;
	cin>>n>>k;

	int *arr = new int[n];
	unordered_map<int,int> m ;

	for(int i =1;i<=n;i++){
		cin>>arr[i];
		m[arr[i]]= i;
	}

	for(int i =n;i>=1 && k>0;i--){
		int best = n-i+1;
		int ind = 0;
		if(m.count(i)){
			ind = m[i];
		}

		if(best != ind){
			swap(arr[best],arr[ind]);
			k--;
			m[arr[best]] = best;
			m[arr[ind]] = ind;
		}
	}

	for(int i =1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}