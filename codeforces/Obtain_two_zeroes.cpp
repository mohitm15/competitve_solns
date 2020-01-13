// contest: Educational Codeforces Round 77 (Rated for Div. 2), problem: (B) Obtain Two Zeroes, Accepted, #
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(long long int i=1;i<n;++i)
#define rf(j,n) for(long long int j=n-2;j>=0;--j)
#define ll long long int
 
using namespace std;
 
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 
int maxi(int a,int b)
{
	int ans;
	ans = a<=b?b:a;
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		if(a<=b)
		{
			if(((a+b)%3==0)&& (2*a>=b))
			cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;		
		}
		else
		{
			if(((a+b)%3==0)&& (2*b>=a))
			cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;
		}
		
	}
	return 0;
}
