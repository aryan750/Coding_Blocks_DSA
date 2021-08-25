#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;

	while(t> 0){
		int l;
		cin>>l;
		int a[l];
		for(int i =0;i<l;i++){
			cin>>a[i];
		}


		unordered_map<int,int> m;

		for(int i =0;i<l;i++){
			m[a[i]]++;
		}

		int n;
		cin>>n;
		int b[n];

		for(int i=0;i<n;i++){
			cin>>b[i];
			if(m.find(b[i]) != m.end()){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		t--;
	}




	return 0;
}