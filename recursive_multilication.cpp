#include<bits/stdc++.h>
using namespace std;

int multiply_rec(int x, int y)
{
	//base case
	if(y==0)
		return 0;
	//recursive case
	return (x + multiply_rec(x,y-1));
}


int main()
{
	int a;
	int b;
	cin>>a>>b;

	if(a<b)
		cout<<multiply_rec(b,a)<<endl;
	else 
		cout<<multiply_rec(a,b)<<endl;
	return 0;
}