#include<bits/stdc++.h>
using namespace std;

void filterchar(char a[], int n)
{
	int j=0;
	while(n>0)
	{
		int last_bit = (n&1);
		if(last_bit)
		{
			cout<<a[j];
		}
		j++;
		n =n>>1;
	}
	cout<<endl;
}

void printsubsets(char a[])
{
	int n=strlen(a);
	for(int i=0;i<(1<<n);i++)
	{
		filterchar(a,i);
	}
}


int main()
{
	char a[100];
	cin>>a;

	printsubsets(a);
	

	return 0;
}