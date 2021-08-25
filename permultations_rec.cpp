#include<bits/stdc++.h>
using namespace std;

void permut(char *in, int i )
{
	//base case
	if(in[i] == '\0')
	{
		cout<<in<<endl;
		
		return;
	}

	//rec case
	for(int j = i;in[j] != '\0';j++)
	{
		swap(in[i], in[j]);
		permut(in, i+1);
		//to restore the original 
		swap(in[i] , in[j]);//backtrcking 
	}
	

}



int main()
{

	char in[100];
	cin>>in;

	permut(in , 0);


	return 0;
}