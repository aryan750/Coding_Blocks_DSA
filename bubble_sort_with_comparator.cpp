#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
	return a>b;
}

void bubble_sort(int a[], int n, bool (&cmp)(int a,int b))
{
	for(int itr=1;itr<n;itr++)
	{
		//Pairwise Swapping 
		for(int j=0;j<(n-itr);j++)
		{
			if (cmp(a[j],a[j+1]))
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}

int main()
{
	int n,key;
	cin>>n;

	int a[1000];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubble_sort(a,n,compare);
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	return 0;
}