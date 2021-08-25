#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int t;
	cin>>t;

	while(t>0)
	{
		string s;
		cin>>s;

		stack<char> stk;
		bool ans = false;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == ')'){
				if(stk.top() == '('){
					ans = true;
				}
				while(!stk.empty() && stk.top() != '('){
					stk.pop();
				}
				if(!stk.empty()){
					stk.pop();
				}
			}
			else{
				stk.push(s[i]);
			}
		}
		if(ans)
			cout<<"Duplicate"<<endl;
		else
			cout<<"Not Duplicates"<<endl;

		t--;
	}




	return 0;
}