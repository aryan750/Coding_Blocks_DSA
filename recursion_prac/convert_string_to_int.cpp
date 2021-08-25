#include<bits/stdc++.h>
using namespace std;

int convertToInt(char *a,int n)
{
	if(n==0)
	{
		return 0;
	}

	//rec case
	int digit  = a[n-1] - '0';
	int ans = convertToInt(a,n-1);
	return ans*10 + digit;	
}

int main()
{	
	char s[10];
	cin>>s;
	int len = strlen(s);
	int x =convertToInt(s,len);
	cout<<x<<endl;
	return 0;
}