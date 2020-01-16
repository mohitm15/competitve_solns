//  contest: Codeforces Round #597 (Div. 2), problem: (B) Restricted RPS, Accepted, #
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
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c;
		string s,t;
		cin>>n>>a>>b>>c;
		cin>>s;
		f0(i,n)
		{
			if(s[i]=='R')
			{
				if(b)t+='P',b--;
				else t+='?';
			}
			if(s[i]=='P')
			{
				if(c)t+='S',c--;
				else t+='?';
			}
			if(s[i]=='S')
			{
				if(a)t+='R',a--;
				else t+='?';
			}
		}
		if(n-a-b-c<(n+1)/2)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			f0(i,n)
			{	
				if(t[i]=='?')
				{
					if(a)cout<<'R',a--;
					else if(b)cout<<'P',b--;
					else cout<<"S";
				}
				else 
					cout<<t[i];
			}
			cout<<endl;
		}
	}
}
