#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row,col;
	cin>>row>>col;
	int a[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}

	int startrow=0;
	int endrow=row-1;
	int startcol=0;
	int endcol=col-1;

	while(startrow<=endrow and startcol <= endcol)
	{
		for(int i=startrow;i<=endrow;i++)
		{
			cout<<a[i][startcol]<<", ";
		}
		startcol++;
		// cout<<startcol;
		for(int i=startcol;i<=endcol;i++)
		{
			cout<<a[endrow][i]<<", ";
		}
		endrow--;

		for(int i=endrow;i>=startrow;i--)
		{
			cout<<a[i][endcol]<<", ";
		}
		endcol--;

		for(int i=endcol;i>=startcol;i--)
		{
			cout<<a[startrow][i]<<", ";
		}
		startrow++;
	}
	cout<<"END"<<endl;

	return 0;
}