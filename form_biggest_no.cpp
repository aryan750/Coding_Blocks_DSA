#include<bits/stdc++.h>
using namespace std;

bool mycompare(string X,string Y)
{
	string XY = X.append(Y);

	string YX = Y.append(X);

	return XY.compare(YX)>0 ? 1 : 0;
}


int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		cin>>n;
		
		string str[n];
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
		}

		sort(str,str+n,mycompare);
		for(int i=0;i<n;i++)
		{
			cout<<str[i];
		}
		cout<<endl;

		t--;
	}
	return 0;
}