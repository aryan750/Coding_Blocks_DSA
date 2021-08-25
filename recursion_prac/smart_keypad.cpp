#include<bits/stdc++.h>
using namespace std;

char keypad[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };


void smart_keypad(char *in, char *out, int i, int j)
{
	//base case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return ;
	}

	//rec case
	int digit = in[i] - '0';


	for(int k=0;keypad[digit][k] != '\0'; k++)
	{
		out[j] = keypad[digit][k];
		smart_keypad(in, out,i+1, j+1);
	}

	return;

}	


int main()
{
	char in[100];
	cin>>in;

	char out[100];

	smart_keypad(in, out, 0, 0);




	return 0;
}