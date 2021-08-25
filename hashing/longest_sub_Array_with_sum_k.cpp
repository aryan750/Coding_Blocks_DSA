#include<bits/stdc++.h>
using namespace std;

int longestSubbarraySum(int arr[], int n, int k){

	unordered_map<int,int> m;
	int pre = 0;
	int max_len = 0;

	for(int i = 0;i<n;i++){
		
		pre += arr[i];
		if(pre == k){
			max_len = max(max_len,i+1);
		}

		if(m.find(pre-k) != m.end()){
			max_len = max(max_len, i - m[pre-k]);
		}
		else{
			m[pre] = i;
		}
	}
	return max_len;
}



int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i =0;i<n;i++){
		cin>>arr[i];
	}

	int k;
	cin>>k;

	cout<<longestSubbarraySum(arr,n,k)<<endl;



	return 0;
}