// contest: Codeforces Round #605 (Div. 3), problem: (C) Yet Another Broken Keyboard, Happy New Year!, #
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;++i)
#define rf(j,n) for(int j=n;j>0;j--)
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
 
int main()
{
	ll n;int k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<char> c(k);
	f0(i,k) cin>>c[i];
	string bi="";int fl=0;
	f0(i,n)
	{
		fl=0;
		f0(j,k)
		{
			if(s[i]==c[j])
			{
				bi+="1";
				fl=1;
				break;
			}
		}
		if(fl==0)
		bi+="0";
	}
	ll ans = count(bi.begin(),bi.end(),'1');
	ll cnt=0;
	f0(i,n)
	{
		if(bi[i]=='1')
		{
			cnt++;
		}
		else
		{
			if(cnt>1)
			{
				ans+=((cnt*(cnt-1))/2);
			}
			cnt=0;
		}
		
	}
	ans+=((cnt*(cnt-1))/2); 
	cout<<ans<<endl;
	return 0;
}
