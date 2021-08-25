#include<bits/stdc++.h>
using namespace std;

int count = 0;

void subseq(char *in, char *out, int i , int j)
{
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<" ";
		::count++;		
		return ;
	}

	//rec case
	//including 

	//excluding
	subseq(in, out,i+1, j);

	out[j] = in[i];
	subseq(in,out, i+1, j+1);


}


int main()
{
	char in[1000];
	cin>>in;
	
	char out[2000];
	
	subseq(in,out,0 ,0);
	cout<<endl;
	cout<<::count<<endl;
	return 0;
}