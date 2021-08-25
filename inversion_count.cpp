#include<bits/stdc++.h>
using namespace std;

int merge(int *a , int s, int e)
{
	int mid= (s+e)/2;

	int i =s;
	int j = mid+1;
	int k = s;

	int cnt =0;
	
	int temp[100000];
	
	while(i <= mid && j <= e)
	{
		if(a[i] <= a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k++] = a[j++];
			cnt += mid - i +1;
		}
	}

	//filling the array if some elements are left in i
	while(i<=mid)
	{
		temp[k++] = a[i++];
	}

	while(j<=e)
	{
		temp[k++] = a[j++];
	}

	//copying all the elements to original array
	for(int i=s;i<=e;i++)
	{
		a[i] = temp[i];
	}

	return cnt;
}




int inversion_count(int *a, int s , int e)
{
	if(s>=e)
		return 0; 

	int mid = (s+e)/2;

	int x = inversion_count(a,s,mid);
	int y = inversion_count(a, mid+1, e);
	//cross inversions
	int z = merge(a, s, e);

	return x+y+z;
}



int main()
{
	int arr[] = {1,5,2,6,3,0};
	int n = sizeof(arr)/sizeof(int);
	int ans = inversion_count(arr, 0 , n-1 );
	cout<<ans<<endl;
	return 0;
}