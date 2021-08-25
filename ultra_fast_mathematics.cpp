#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;

		int n =s1.size();

		for(int i=0;i<n;i++)
		{
			if(s1[i] == s2[i])
				cout<<"0";
			else 
				cout<<"1";
		}
		cout<<endl;



		t--;
	}



	return 0;
}