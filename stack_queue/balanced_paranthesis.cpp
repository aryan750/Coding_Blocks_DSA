#include<bits/stdc++.h>
using namespace std;

bool isValid(char *s)
{
	stack<char> stk;

	for(int i=0;s[i] != '\0';i++)
	{
		char ch = s[i];

		if(s[i] == '(')
			stk.push(ch);

		else if(ch == ')')
		{
			if(stk.empty() || stk.top() != '(')
				return false;
			stk.pop();
		}
	}
	return stk.empty();
}

int main()
{
	char s[100] = "((a+b)) + (c-d+f))";
	if(isValid(s))
		cout<<"It is valid a string"<<endl;
	else
		cout<<"It is not a valid string"<<endl;

	return 0;
}