#include<bits/stdc++.h>
using namespace std;

//first method
//worst case 64 iterations in long long int 
int countBits(int n)
{
	int ans=0;
	while(n>0)
	{
		ans += (n&1);
		n = n>>1;
	}
	return ans;
}


//second method
//worst case time is O(no. of set bits)=O(log n)
int countBitsFast(int n)
{
	int ans=0;
	while(n>0)
	{
		n = n&(n-1);
		ans++;
	}
	return ans;
}

//third methid is inbuilt finction 

int main()
{
	int n;
	cin>>n;

	cout<<countBits(n)<<endl;
	cout<<countBitsFast(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;
	return 0;
}