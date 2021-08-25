#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int xo= 0;
	int a[100004];
	//find xor of all the no
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		xo = (xo^a[i]);
	}
	int tem= xo;
	int pos =0;
	//check where is first one set bit in xor no
	while((tem&1) != 1)
	{
		pos++;
		tem = tem>>1;
	}
	int form = (1<<pos);
	//we will do & xo with all the a[i]
	// check if it is grater than 0

	int x = 0;
	int y = 0;
	for(int i=0;i<n;i++)
	{
		if((form & a[i])>0)
		{
			x = x^a[i];
		}
	}
	y = x^xo;
	cout<<min(x,y)<<" "<<max(x,y)<<endl;



	return 0;
}