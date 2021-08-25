#include<bits/stdc++.h>
using namespace std;

char keypad[][10] = {"","","ABC","EFG","GHI","IJKL","MNO","PQRS","TUV","WXYZ"};

void generating_names(char *in, char *out, int  i, int j)
{
	//base case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	//rec case
	int digit = in[i] - '0';

	if(digit == 0 || digit == 1)
	{
		generating_names(in, out, i+1, j);
	}

	for(int k = 0;keypad[digit][k] != '\0';k++)
	{
		out[j] = keypad[digit][k];
		generating_names(in, out, i+1, j+1);
	}
}

int main()
{
	char in[100];
	char out[100];
	cin>>in;

	generating_names(in, out, 0,0);
	return 0;
}