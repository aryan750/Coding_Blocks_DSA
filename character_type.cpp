#include<bits/stdc++.h>
using namespace std;

int main()
{
	char ch;
	cin>>ch;

	if(isalpha(ch))
	{
		if(isupper(ch))
			cout<<"U"<<endl;
		else
			cout<<"L"<<endl;
	}
	else 
		cout<<"I"<<endl;




	return 0;
}