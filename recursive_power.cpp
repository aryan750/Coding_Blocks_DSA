#include<bits/stdc++.h>
using namespace std;
//less efficient
int power_f(int a , int n)
{
	//base case
	if( n == 0)
		return 1;

	//recursive case
	return (a*power_f(a,n-1));
}

//more efficient
int fast_power(int a, int n)
{
	//base case
	if(n == 0)
		return 1;
	int smaller_ans = fast_power(a,n/2);
	smaller_ans *= smaller_ans;

	if(n&1)
		return smaller_ans *a;
	return smaller_ans;



}

int main()
{
	int a;
	cin>>a;

	int n;
	cin>>n;

	cout<<power_f(a,n)<<endl;

	return 0;
}