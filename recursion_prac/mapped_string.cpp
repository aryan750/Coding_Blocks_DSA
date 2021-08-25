#include<bits/stdc++.h>
using namespace std;

void mapped_strig(char *in , char *out, int i , int j)
{

	//base case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return ;
	}

	//rec case
	//one at a time
	int digit = in[i] - '0';
	char ch = digit + 'A' -1;
	out[j] = ch;
	mapped_strig(in, out, i+1, j+1);

	//two at a time
	if(in[i+1] != '\0')
	{
		int sec = in[i+1] - '0';
		int no = digit*10 + sec;
		if(no <= 26)
		{
			ch = no + 'A' - 1;
			out[j] = ch;
			mapped_strig(in, out , i+2, j+1);
		}
	}
	return ;
}


int main()
{
	char in[20];
	cin>>in;

	char out[10000];
	mapped_strig(in, out , 0, 0); 

	return 0;
}