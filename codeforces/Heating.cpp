// contest: Educational Codeforces Round 77 (Rated for Div. 2), problem: (A) Heating, Accepted, #
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
		ll n,k,ans=1,w,r;
		cin>>n>>k;
		if(n==1)
		ans=k*k;
		else if(k==1)
		ans=1;
		else
		{
			w = k/n;
			r = k%n;
			ans = (w*w)*(n-r)+ r*((w+1)*(w+1));
		}
		cout<<ans<<endl;
	}
	return 0;
}
