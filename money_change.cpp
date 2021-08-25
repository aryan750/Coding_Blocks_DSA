//rotate(arr,arr+2,arr+n) can be used to traverse array from second index
//next_permutation(v.begin(),v.end()) can be used to give 
//differnet permutation using all the elements  


#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
	return a<=b;
}



int main()
{
	int coins[]={1,2,5,10,20,50,100,200,500};
	int money=168;

	int n=sizeof(coins)/sizeof(int);

	while(money>0)
	{
		int lb= lower_bound(coins,coins+n,money,compare)-coins -1; //return the index
		int m=coins[lb];
		cout<<m<<", ";
		money = money - m;
	}



	return 0;
}