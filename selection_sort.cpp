#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)
{
	int min_index;

	for(int i=0;i<n-1;i++)
	{	
		min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j] < a[min_index])
			{
				min_index = j;
			}
			swap(a[min_index],a[i]);
		}

	}




}



int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	selection_sort(a,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<endl;
	}



	return 0;
}