#include<bits/stdc++.h>
using namespace std;

void f(char *s, int i)
{
	//base case
	if(s[i] == '\0' || s[i+1] == '\0')
		return;
	
	//rec case
	if(s[i] == s[i+1])
	{
		int j = i+1;

		while(s[j] != '\0')
			j++;

		while(j>=i)
		{
			s[j+1] = s[j];
			j--;
		}
		s[i+1] = '*';
		f(s,i+2);
	}
	else
		f(s,i+1);
	return ;
}

int main()
{

	char s[2000];
	cin>>s;

	f(s,0);
	cout<<s<<endl;

	return 0;
}