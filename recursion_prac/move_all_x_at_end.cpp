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
	if(in[i] == 'x')
	{
		int k=i;
		while(in[k] != '\0')
		{
			in[k] = in[k+1];
			k++;
		}
		in[k] = 'x';
		move(in, i);
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