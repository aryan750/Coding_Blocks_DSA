#include<bits/stdc++.h>
using namespace std;

long long int distance(long long int x, long long int y){
	return x*x + y*y;
}

int main(){

	long long int q;
	cin>>q;
	long long int k;
	cin>>k;
	long long int g= 0;

	priority_queue<long long> heap;	

	while(q > 0){
		long long int d;
		cin>>d;

		if(d == 1){

			long long int x;
			long long int y;
			cin>>x>>y;

			if(g < k){
				heap.push(distance(x,y));
				g++;
			}
			else{
				if(distance(x,y) < heap.top()){
					heap.pop();
					heap.push(distance(x,y));
				}
			}

		}
		else if(d == 2){
				
			cout<<heap.top()<<endl;
			
		}
		q--;
	}
	return 0;
}