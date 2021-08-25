#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	string a = reverse(s.rbegin(),s.rend());
	if(s == a)
	{
		cout<<"palindrome"<<endl;
	}
	else
		cout<<"not palindrome"<<endl;
	return 0;
}