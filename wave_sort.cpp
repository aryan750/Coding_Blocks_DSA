#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1,3,4,2,7,8};

	int n = sizeof(a)/sizeof(int);

	for(int i=0;i<n;i+=2)
	{
		//previos elemnt
		if(i!=0 && a[i] < a[i-1])
			swap(a[i], a[i-1]);
		
		//next elemnt
		if(i!=(n-1) && a[i] < a[i+1])
			swap(a[i] , a[i+1]);
	}

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;



	return 0;
}