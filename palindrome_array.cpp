#include<bits/stdc++.h>
using namespace std;

int getpalindrome(int a[],int l, int h)
{	
	if( h-l == 1 || l==h)
		return 1;
	else
	{
		if(a[l] == a[h])
			getpalindrome(a,l+1,h-1);
		else 
			return 0;
	}
}



int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l=0;
	int h=n-1;
	int ans=getpalindrome(a,l,h);

	if(ans)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}