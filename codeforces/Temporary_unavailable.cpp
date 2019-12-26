// Contest: Codeforces Round #610 (Div. 2), problem: (A) Temporarily unavailable
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░  ░░░░░  ░░░█░░░░░
// ░░░░░░█░░░░░░ ░ ░░░ ░ ░░░█░░░░░
// ░░░░░░▀░░░░░░ ░░ ░ ░░ ░░░▀░░░░░
// ░░░░░░░░░░░░░ ░░░ ░░░ ░░░░░░░░░
 
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
  
 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,r;
		cin>>a>>b>>c>>r;
		ll ans=0;
		if(a == b)
		{
			ans =0;
			cout<<ans<<endl;
		}
		else if(a<b)
		{
			for(ll i=a;i<b;)
			{
				i++;
				if((i<=(c-r)) || (i>(c+r)))
				{
					ans++;
					//cout<<i<<" ";
				}
			}
			cout<<ans<<endl;
		}
		else if(a>b)
		{
			for(ll i=a;i>b;)
			{
				i--;
				if((i>=(c+r)) || (i<(c-r)))
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
