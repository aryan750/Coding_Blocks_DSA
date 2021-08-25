#include<bits/stdc++.h>
using namespace std;

int findLargestSeq(int *a, int n){

	unordered_set<int> s;
	for(int i =0;i<n;i++){
		s.insert(a[i]);
	}

	int max_streak = 1;
	for(int i = 0;i<n;i++){

		if(s.find(a[i] - 1) == s.end()){
			int next_no = a[i] + 1;
			int streak_len = 1;
			while(s.find(next_no)!=s.end()){
				streak_len++;
				next_no++;
			}
			max_streak = max(streak_len,max_streak);
		}
	}
	return max_streak;
}


int main(){

	int arr[]= {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
	int p = sizeof(arr)/sizeof(int);

	cout<<findLargestSeq(arr,p)<<endl;

	return 0;
}