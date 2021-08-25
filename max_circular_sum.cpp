	#include<bits/stdc++.h>
	using namespace std;

	int main()
	{
		int t;
		cin>>t;
		
		while(t>0)
		{
			int n;
			cin>>n;
			int a[n];
			if(n==0)
			{
				break;
			}
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}



			int sum=0;
			for(int i=0;i<n;i++)
			{
				sum += a[i];
			}

			//negating the array
			for(int i=0;i<n;i++)
			{
				a[i] = a[i]*(-1);
			}

			int curr_sum=0;
			int max_sum=INT_MIN;
			for(int i=0;i<n;i++)
			{
				curr_sum=max(curr_sum+a[i],a[i]);
				max_sum=max(max_sum,curr_sum);
			}

			//negating again
			max_sum=max_sum*(-1);

			sum -= max_sum;
			cout<<sum<<endl;

			t--;
		}
		return 0;
	}