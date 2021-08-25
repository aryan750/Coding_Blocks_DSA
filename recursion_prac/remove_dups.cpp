#include<bits/stdc++.h>
using namespace std;

void dups(char *in,char *out,int i,int j)
{
	//base case
	if(in[i+1] == '\0')
	{			
		out[j] = in[i];
		cout<<out<<endl;
		return;
	}

	//rec case
	out[j] = in[i];
	if(in[i] == in[i+1])
	{
		while(in[i] == in[i+1])
		{
			out[j] = in[i];
			i++;
		}
		dups(in,out,i+1,j+1);
	}
	else
	{
		dups(in,out,i+1,j+1);
	}
	return;
}


int main()
{
	char in[10001];
	cin>>in;
	char out[10001];
	int n = strlen(in);

	dups(in,out,0,0);
	


	return 0;
}