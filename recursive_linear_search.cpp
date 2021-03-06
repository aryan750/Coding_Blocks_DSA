#include<bits/stdc++.h>
using namespace std;

//stroring all the occurences of key in another array
int storeOcc(int *a , int i, int n, int *out,int j)
{
	//base case
	if( i== n)
		return j;
	if(a[i] == key)
	{
		out[j] = i;
		return storeOcc(a,i+1,n,key,out,j+1);
	}
	return storeOcc(a,i+1,n,key,out,j);
}




void allOcc(int *a, int i , int n, int key)
{
	//base case
	if(i == n)
		return;
	if(a[i] == key)
	{
		cout<<i<<" ,";
	}
	allOcc(a,i+1,n,key);
}


int firstOcc(int *a, int n ,int key)
{
	//base case
	if(n == 0)
		return -1;

	if(a[0] == key)
		return 0;

	int i = firstOcc(a+1,n-1,key);
	if(i == -1)
		return -1;

	return i+1;
}

int lastOcc(int *a, int n, int key)
{
	//base case
	if(n==0)
		return -1;

	//rec case
	int i = lastOcc(a+1, n-1, key);
	if( i == -1)
	{
		if(a[0] == key)
			return 0;
		else
			return -1;
	}
	//otherwise if i returned by subproblem is not -1
	return i+1;
}


int main()
{
	int arr[] = {1,2,3,7,4,5,6,7,10};
	int n = sizeof(arr)/sizeof(int);

	int key = 7;

	cout<<firstOcc(arr,n ,key)<<endl;
	cout<<lastOcc(arr,n , key)<<endl;
	allOcc(arr, 0, n ,key);
	return 0;
}