#include<bits/stdc++.h>
using namespace std;


void replace_pi(char a[], int i)
{
	//base case
	if(a[i] == '\0' || a[i+1] == '\0')
		return ;

	//rec case
	if(a[i] == 'p' && a[i+1] == 'i')
	{
		int j = i+2;

		while(a[j] != '\0')
			j++;

		while(j>=i+2)
		{
			a[j+2] = a[j];
			j--;
		}

		a[i] = '3';
		a[i+1] = '.';
		a[i+2] = '1';
		a[i+3] = '4';
		replace_pi(a,i+4);
	}
	else
	{
		replace_pi(a,i+1);
	}
	return ;
}



int main()
{
	int n;
	cin>>n;

	while(n>0)
	{

		char a[1000];
		cin>>a;
		replace_pi(a, 0);
		cout<<a<<endl; 
		
		n--;
	}



	return 0;
}