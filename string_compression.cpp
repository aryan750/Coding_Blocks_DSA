#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int n=s.size();

	int i=0;
	char ch=s[0];
	int count = 0;
	while(s[i]!='\0')
	{
		if(ch == s[i])
		{
			count++;
		}
		else
		{
			cout<<ch<<count;
			ch=s[i];
			count = 1;
		}

		i++;
	}
	cout<<ch<<count<<endl;
	return 0;
}