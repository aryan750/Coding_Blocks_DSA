#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	stack<int> s;

	while(n>0){
		int d;
		cin>>d;
		if(d == 1){
			if(s.empty()){
				cout<<"No Code"<<endl;
			}
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}


		if(d == 2){
			int k;
			cin>>k;
			s.push(k);
		}
		n--;
	}




	return 0;
}