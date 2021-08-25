#include<bits/stdc++.h>
using namespace std;


int  main()
{
	int n;
	cin>>n;
	deque<int> dq1;
	deque<int> dq2;

	int a[n];
	for(int i =0 ;i<n;i++)
	{
		cin>>a[i];
		dq1.push_back(a[i]);
	}
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		dq2.push_back(b[i]);
	}
	int count = 0;

	while(!dq1.empty() || !dq2.empty()){

		if(dq1.front() == dq2.front()){
			count += 1;
			dq1.pop_front();
			dq2.pop_front();
		}
		else{
			while(dq1.front() != dq2.front()){
				int data;
				data = dq1.front();
				dq1.pop_front();
				dq1.push_back(data);
				count++;
			}
		}
	}

	cout<<count<<endl;




	return 0;
}