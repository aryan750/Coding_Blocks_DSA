#include<bits/stdc++.h>
using namespace std;

void move(int n, char src, char dest, char helper)
{
	//base case
	if(n==0)
		return ;

	//rec case
	move(n-1, src,helper,dest);
	cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
	move(n-1 , helper, dest, src);

}

int main()
{
	int n;
	cin>>n;

	move(n,'A','B','C');



	return 0;
}