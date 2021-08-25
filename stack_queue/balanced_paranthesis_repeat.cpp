#include<bits/stdc++.h>
using namespace std;

bool isValid(char *s)
{
	stack<char> stk;

	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			stk.push(s[i]);
		else if(!stk.empty() && s[i] == ')' && stk.top() != '(')
			return false;
		else if(!stk.empty() && s[i] == '}' && stk.top() != '{')
			return false;
		else if(!stk.empty() && s[i] == ']' && stk.top() != '[')
			return false;
		else
			stk.pop();
	}
	return stk.empty();
}




int main()
{
	char ch[100000];
	cin>>ch;


	if(isValid(ch))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
 

	return 0;
}