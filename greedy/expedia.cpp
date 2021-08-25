#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<int,int> p1, pair<int,int> p2){
	return p1.first > p2.first;
}


int main(){

	int n ,t, x, d,f,D,F,prev = 0;

	// cin>>t;

	// while(t--){

		int flag = 0;
		int ans = 0;

		priority_queue<int> pq;
		vector<pair<int,int> > v;

		cin>>n;

		for(int i =0 ;i < n ;i++ ){
			cin>>d>>f;
			v.push_back(make_pair(d,f));
		}

		sort(v.begin(),v.end(),mycompare);

		cin>>D>>F;

		for(int i = 0 ;i<n;i++){
			v[i].first = D - v[i].first;
		}


		//prev denotes the previous city we have visited
		prev = 0;
		//current city
		x = 0;

		while(x < n){
			//if we have enough fuel to reach the next station 
			if( F >= (v[x].first - prev)){

				F = F - (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else{
				//chech if we have enough fuel
				if(pq.empty()){
					flag = 1;
					break;
				}
				//otherwise refuel the truck wih highest capacity in queue
				F += pq.top();
				pq.pop();
				ans = ans+1;
				continue;
			}
			x++;
		}

		//we have actually travelled through n
		//what is left is you have to reach the town from the last station 
		if(flag == 1){
			cout<<-1<<endl;
			// continue;
		}
		//otherwise
		D = D - v[n-1].first;

		// if(F >= D){
		// 	cout<<ans<<endl;
		// 	// continue;
		// }
		//otherwise
		while(F < D){

			if(pq.empty()){
				flag = 1;
				break;
			}
			F += pq.top();
			pq.pop();
			ans = ans + 1;
		}	

		if(flag == 1){
			cout<<-1<<endl;
			// continue;
		}
		cout<<ans<<endl;
		
	// }


	return 0;
}