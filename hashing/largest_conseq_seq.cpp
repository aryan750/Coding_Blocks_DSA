#include<bits/stdc++.h>
using namespace std;

int findLargestSeq(int *arr, int n){

	unordered_map<int,int > m;

	for(int i =0;i<n;i++){
		int no = arr[i];

		if(m.count(no-1) == 0 && m.count(no+1) == 0){
			m[no] = 1;
		}
		else if(m.count(no-1) && m.count(no+1)){
			int len1 = m[no-1];
			int len2 = m[no+1];

			int streak = len1 + 1 + len2;
			m[no-len1] = streak;
			m[no+len1] = streak;
		}
		else if(m.count(no-1) == 0 && m.count(no+1)){
			int len = m[no+1];
			m[no+len] = len+1;
			m[no] = len+1;
		}
		else{
			int len = m[no-1];
			m[no-len] = len+1;
			m[no] = len+1;
		}
	}

	int max_len = 0;

	for(auto x : m){
		max_len = max(max_len,x.second);
	}
	return max_len;
}



int main(){

	int n;
	cin>>n;

	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}

	cout<<findLargestSeq(a,n)<<endl;


	return 0;
}