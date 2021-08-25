#include<bits/stdc++.h>
using namespace std;

typedef pair <long long int, pair<long long int, long long int >> node;

vector<long long int> merger(vector<vector<long long int>> arr,int m, int n){

	vector<long long int> result;
	priority_queue<node,vector<node>,greater<node>> q;

	for(int i =0;i<m;i++){
		q.push({arr[i][0],{i,0}});
	}

	while(!q.empty()){

		node current = q.top();
		q.pop();

		long long int element = current.first;
		long long int x = current.second.first;
		long long int y = current.second.second;
		result.push_back(element);

		if( y + 1 < n){
			q.push({arr[x][y+1],{x,y+1}});
		}
	}
	return result;
}

int main(){

	int k,n;
	cin>>k>>n;
	long long int mu = k*n;
	vector<vector<long long int>> arr(k,vector<long long int>(n));
	for(int i =0;i<k;i++){
		for(int j =0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	vector<long long int> output = merger(arr, k,n);
	for(auto a : output){
		cout<<a<<" ";
	}
	cout<<endl;

	return 0;
}