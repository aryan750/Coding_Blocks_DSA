#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return 1;

	//rec case
	return f(n-1)+ (n-1)*f(n-2);
}



int main()
{
	int n;
	cin>>n;
	int k =f(n);
	cout<<k<<endl;

	return 0;
}