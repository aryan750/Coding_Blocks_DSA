#include<bits/stdc++.h>
using namespace std;
int count = 0;
char keypad[][9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wx","yz"};


void code(char *in, char *out, int i, int j)
{
	//base case
	if(in[i] == '\0')
	{
		out[j] = in[i];
		cout<<out<<" ";
		::count++;
		return ;
	}

	//rec case
	int digit = in[i] - '0' - 1;
	for(int k = 0;keypad[digit][k] != '\0';k++)
	{
		out[j] = keypad[digit][k];
		code(in ,out ,i+1, j+1);
	}


}


int main()
{
	char in[100];
	char out[200];

	cin>>in;

	code(in, out ,0,0);
	cout<<endl;
	cout<<::count<<endl;



	return 0;
}