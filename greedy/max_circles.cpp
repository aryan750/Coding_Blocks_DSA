#include<bits/stdc++.h>
using namespace std;

class Circle{
public:
	long int center;
	long int radius;
};

bool mycompare(Circle a, Circle b){
	return (a.center + a.radius) < (b.center + b.radius);
}

int main(){

	unsigned int n;
	cin>>n;
	Circle a[n];


	for(int i= 0;i<n;i++){
		cin>>a[i].center>>a[i].radius;
		
	}

	sort(a,a+n,mycompare);
	int count = 1;
	int end = a[0].center + a[0].radius;
	
	
	for(int i = 1;i < n ; i++){
		int st = a[i].center - a[i].radius;
		if(end <= st){
			count++;
			end = a[i].center + a[i].radius;
		}
	}


	cout<<(n - count)<<endl;

	return 0;
}