#include<bits/stdc++.h>
using namespace std;

int string_to_int(char *a, int n)
{
	//base case
	if(n==0)
		return 0  ;

	//recursive case
	int digit = a[n-1] - '0'; //last digit 

	int small_ans = string_to_int(a,n-1);
	return small_ans*10 + digit;

}



int main()
{
	char a[] = "1234";
	int len = strlen(a);
	int x = string_to_int(a,len);
	cout<<x<<endl;

	return 0;
}