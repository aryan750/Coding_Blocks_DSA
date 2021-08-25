#include<bits/stdc++.h>
using namespace std;

int main(){

	//maxHeap
	priority_queue<int> pq;
	
	//minHeap
	// priority_queue<int, vector<int> , greater<int> > pq;

	int n;
	cin>>n;

	for(int i =0;i<n;i++){
		int no;
		cin>>no;
		pq.push(no);
	}


	//remove the element from the heap
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}


	return 0;
}