#include<bits/stdc++.h>
using namespace std;


int main()
{

	set<int> s;
	int arr[] = {10,11,20,12,30,40,10};
	int n = sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}

	//print all the elements
	for(set<int>::iterator it = s.begin(); it != s.end();it++){
		cout<<*(it)<<" ,";
	}
	return 0;
}