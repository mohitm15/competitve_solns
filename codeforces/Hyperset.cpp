// contest: Codeforces Round #612 (Div. 2), problem: (B) Hyperset, Happy New Year!, 
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
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


string func(char a,char b)
{
	if(a!='S'&&b!='S')
		return "S";
	if(a!='E'&&b!='E')
		return "E";
	if(a!='T'&&b!='T')
		return "T";
}

map<string,ll> mp;
string s[2005];
ll ans = 0;

int main() 
{
	int n,k;
	cin>>n>>k;
	f0(i,n)
	{
		cin>>s[i];
		mp[s[i]] = 1;
	}
	f0(i,n)
	{
		for(int j=i+1;j<n;j++)
		{
			string temp = "";
			f0(l,k)
			{
				if(s[i][l] == s[j][l])
					temp += s[i][l];
				else
					temp += func(s[i][l],s[j][l]);
			}
			//cout<<temp<<"\n";
			ans += mp[temp];
		}
	}
	cout<<ans/3;
  return 0;
}
