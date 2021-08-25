#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k,s;
	cin>>n;
	cin>>m;
	char a[n][m];
	cin>>k;
	cin>>s;

	int success = true;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s < k)
			{
				success=false;
				break;
			}		
			if(a[i][j] == '.')
			{
				s -= 2;				
			}
			else if(a[i][j] == '*')
			{
				s += 5;
			}		
			else //#
				break;
			
			if(j != n-1)
			{
				s--;	
			}				
		}
	}

	if(success)
	{
		cout<<"Yes"<<endl<<s<<endl;
	}
	else 
		cout<<"No"<<endl;

	return 0;
}