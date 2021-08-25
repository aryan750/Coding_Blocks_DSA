#include<bits/stdc++.h>
using namespace std;
char words[][10] = {"zero", "one", "two", "three" , "four" , "five" , "six", "seven" , "eight", "nine"};

void print_spelling(int n)
{
	if(n==0)
		return ;
	
	print_spelling(n/10);

	int digit = n%10;
	cout<<words[digit]<<" ";
	return;
}


int main()
{
	int n;
	cin>>n;

	print_spelling(n);

	return 0;
}