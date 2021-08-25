#include<bits/stdc++.h>
using namespace std;

char maxfrequency(string str)
{
	char result;
	int count[256] = {0};

	int max=0;
	int l = str.size();
	for(int i=0;i<l;i++)
	{
		count[str[i]]++;

		if(count[str[i]] > max)
		{
			max = count[str[i]];
			result = str[i];
		}
	}
	return result;
}

int main()
{
	string str;
	cin>>str;

	cout<<maxfrequency(str);




	return 0;
}