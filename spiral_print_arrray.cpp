#include<bits/stdc++.h>
using namespace std;


void spiral(int a[][1000],int n,int m)
{
	int startrow=0;
	int endrow=m-1;
	int startcol=0;
	int endcol=n-1;

	while(startrow<=endrow and startcol<=endcol)
	{
		//startrow
		for(int i=startcol;i<=endcol;i++)
		{
			cout<<a[startrow][i]<<" ";
		}
		startrow++;
		
		//endcol
		for(int i=startrow;i<=endrow;i++)
		{
			cout<<a[i][endcol]<<" ";
		}
		endcol--;
		
		// //endrow
		// if(endrow > startrow)
		// {
			for(int i=endcol;i>=startcol;i--)
			{
				cout<<a[endrow][i]<<" ";
			}
			endrow--;

		// }

		//startcol
		// if(endcol > startcol)
		// {
			for(int i=endrow;i>=startrow;i--)
			{
				cout<<a[i][startcol]<<" ";
			}
			endrow++;
		// }
	}  

}


int main()
{
	int a[1000][1000]={0};;
	int n,m;
	cin>>n;
	cin>>m;
	int val=1;
	//input a 2d array
	for(int row=0;row<m;row++)
	{
		for(int column=0;column<n;column++)
		{
			a[row][column] = val;
			val=val+1;
			cout<<a[row][column]<<" ";
		}
		cout<<endl;
	}
	spiral(a,n,m);	
	return 0;
}