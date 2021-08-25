#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

	
	int t;
	cin>>t;


	while(t > 0){

		priority_queue<ll> left;
		priority_queue<ll, vector<ll> , greater<ll>> right;

		ll k;
		cin>>k;
		ll n;
		cin>>n;
		left.push(n);

		int med = n;
		cout<<med<<" ";

		while(k>1){

			cin>>n;
			if(left.size() > right.size()){
				
				if( n < med){

					right.push(left.top());
					left.pop();
					left.push(n);
				}
				else{
					right.push(n);
				}
				med = (left.top() + right.top())/2;
			}

			else if( left.size() == right.size()){

				if(n < med){

					left.push(n);
					med = left.top();
				}
				else{
					right.push(n);
					med = right.top();
				}
			}

			else{
				 if(n > med ){

				 	left.push(right.top());
				 	right.pop();
				 	right.push(n);
				 }
				 else{
				 	left.push(n);
				 }
				 med = (left.top() + right.top())/2;
			}
			cout<<med<<" ";
			
			k--;
		}
		cout<<endl;
		t--;
	}


	return 0;
}