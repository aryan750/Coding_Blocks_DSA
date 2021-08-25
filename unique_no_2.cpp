#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[100005];
	int no;
	int x=0;

	for(int i=0;i<n;i++)
	{
		cin>>no;
		a[i]= no;
		x = x^no;
	}

	//xor = a^b
	int temp=x;
	int pos =0;
	while((temp&1) != 1)
	{
		pos++;
		temp = temp>>1;
	}

	//the first bit in xor is at postion 'pos'
	int mask (1<<pos);

	//find those no which contain set bit at position pos
	int xa=0;
	int y=0;
	for(int i=0;i<n;i++)
	{
		if((a[i] & mask) >0)
		{
			xa = xa^a[i];
		}
	}
	y = x ^ xa;

	cout<<min(xa,y)<<" "<<max(xa,y)<<endl;

	return 0;
}