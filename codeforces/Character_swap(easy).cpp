// contest: Codeforces Round #599 (Div. 2), problem: (B1) Character Swap (Easy Version), Happy New Year!, #
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
 
 
int maxi(int a,int b)
{
	int ans = a>=b?ans=a:ans=b;
	return ans;
}
 
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int arr[n];
		int flag=0,cnt=0,ind=0;
		f0(i,n)
		{
			if(s[i]!=t[i])
			{
				cnt++;
				arr[ind]=i;
				ind++;
			}
		}
		if(cnt!=2 && cnt!=0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			if((s[arr[0]]==s[arr[1]]) && (t[arr[0]]==t[arr[1]]) && (s[arr[0]]!=t[arr[0]]))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}
