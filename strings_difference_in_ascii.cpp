#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int m = s.size();
	for(int i=0;i<m-1;)
	{
		int n= int(s[i+1]) - int(s[i]);
		cout<<s[i]<<n;
		
		if(s[i] == s[m-2])
			cout<<s[m-1];

		i++;
	}




	return 0;
}