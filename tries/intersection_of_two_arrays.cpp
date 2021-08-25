#include<bits/stdc++.h>
using namespace std;



vector<int> findIntersection(int *a, int *b, int n){

	map<int, int > m;
	vector<int>v;

	for(int i = 0;i<n;i++){
		m[a[i]]++;
	}
	for(int i = 0;i<n;i++){
		
		if(m.find(b[i]) != m.end()){
			if(m[b[i]] >= 1){
				m[b[i]]--;
				v.push_back(b[i]);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;

}



int main(){

	int n;
	cin>>n;
	int a[n];

	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int b[n];
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}

	vector<int> v= findIntersection(a,b,n);
	cout<<"[";
	for(auto it = v.begin();it!=v.end();it++){
		cout<<*it;
		if(it != prev(v.end())){
			cout<< ", ";
		}
	}
	cout<<"]";
	cout<<endl;

	return 0;
}