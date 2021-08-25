#include<bits/stdc++.h>
using namespace std;

int place_the_tile(int n)
{

	//base case 
	if(n<=3)
		return 1;
	int a = place_the_tile(n-1);
	int b = place_the_tile(n-4);

	return (a+b);
}



int main()
{
	int n;
	cin>>n;

	int k = place_the_tile(n);
	cout<<k<<endl;
	return 0;
}