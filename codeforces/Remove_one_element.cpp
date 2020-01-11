// contest: Codeforces Round #605 (Div. 3), problem: (D) Remove One Element, Happy New Year!, #
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
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> l(n,1);
	vector<ll> r(n,1);
	int ans=1;
	f0(i,n) cin>>a[i];
	f1(i,n)
	{
		if(a[i-1]<a[i])
		{
			l[i]=l[i-1]+1;
		}
		ans=maxi(ans,l[i]);
	}
	rf(i,n)
	{
		if(a[i]<a[i+1])
		{
			r[i]=r[i+1]+1;
		}
		ans=maxi(ans,r[i]);
	}
	// f0(i,n)
	// cout<<l[i]<<" ";
	// next;
	// f0(i,n)
	// cout<<r[i]<<" ";
	// next;
	for(int i=0;i<n-2;i++)
		if(a[i]<a[i+2])
		ans = maxi(ans,l[i]+r[i+2]);
	
	cout<<ans<<endl;
	// ll ans = *max_element(a.begin(),a.end());
	// ll maxindex = max_element(a.begin(),a.end())-a.begin();
	return 0;
}
