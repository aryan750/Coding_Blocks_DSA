#include<bits/stdc++.h>
using namespace std;

string extractstringwithkey(string str,int key)
{
	char *s= strtok((char *)str.c_str()," ");
	while(key>1)
	{
		s= strtok(NULL," ");
		key--;
	}
	return s;
}

int converttoint(string s)
{
	int ans=0;
	int p=1;
	for(int i=s.length()-1;i>0;i--)
	{
		ans=((s[i]-'0')*p);
		p*=10;
	}
	return ans;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2)
{
	string key1,key2;
	key1=s1.second;
	key2=s2.second;

	return converttoint(key1) < converttoint(key2);
}

bool lexicoCompare(pair<string,string> s1,pair<string,string> s2)
{
	string key1,key2;
	key1=s1.second;
	key2=s2.second;

	return key1 < key2;
}


int main()
{
	int n;
	cin>>n;
	cin.get();

	string a[100];
	for(int i=0;i<n;i++)
	{
		getline(cin,a[i]);
	}
	
	int key;
	string reversal,ordering;
	cin>>key>>reversal>>ordering;

	pair<string,string> strpair[100];

	for(int i=0;i<n;i++)
	{
		strpair[i].first=a[i];
		strpair[i].second=extractstringwithkey(a[i],key);
	}

	//ordering 
	if(ordering == "numeric")
	{
		sort(strpair,strpair+n,numericCompare);
	}
	else
		sort(strpair,strpair+n,lexicoCompare);


	//reversal
	if(reversal=="true")
	{
		for(int i=0;i<n/2;i++)
		{
			swap(strpair[i],strpair[n-i-1]);
		}
	}

	//print
	for(int i=0;i<n;i++)
	{
		cout<<strpair[i].first<<endl;
	}

	return 0;
}