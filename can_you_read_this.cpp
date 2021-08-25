#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	for(int i=0;i<s.size(); )
	{
		if(isupper(s[i]))
		{
			cout<<s[i];
			i++;
		}
		while(!isupper(s[i]) && i<s.size())
		{
			cout<<s[i];
			i++;
		}
		cout<<endl;
	}
	return 0;
}