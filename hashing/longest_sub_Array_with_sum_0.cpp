#include<bits/stdc++.h>
using namespace std;

int longestSubbarraySum(int arr[], int n){

	unordered_map<int,int> m;
	int pre = 0;
	int max_len = 0;

	for(int i = 0;i<n;i++){
		
		pre += arr[i];
		if(pre == 0){
			max_len = max(max_len,i+1);
		}

		if(m.find(pre) != m.end()){
			max_len = max(max_len, i - m[pre]);
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

	cout<<longestSubbarraySum(arr,n)<<endl;



	return 0;
}