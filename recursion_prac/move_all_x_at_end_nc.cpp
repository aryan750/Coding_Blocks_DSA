#include<bits/stdc++.h>
using namespace std;

void move(char *in, int i)
{
	//base case
	if(in[i] == '\0')
	{
		cout<<in<<endl;
		return ;
	}

	//rec case
	if(in[i] != 'x')
	{
		cout<<x<<endl;
	}
	else
		move(in,i+1);
	return ;
}

int main()
{	
	char in[10000];
	cin>>in;
	move(in, 0);

	return 0;
}