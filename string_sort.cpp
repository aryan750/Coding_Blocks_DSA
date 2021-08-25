#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool myCompare(string a,string b)
{
    int l1=a.size();
    int l2=b.size();
    int flag=-1;
	for(int i=0;i<min(l1,l2);i++){
		if(a[i]!=b[i])
			flag=0;
		}
	if(flag==-1)
		return a>b;
	else
		return a<b;
}

int main()
{
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n,myCompare);
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}