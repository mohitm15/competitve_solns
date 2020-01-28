// contest: Codeforces Round #595 (Div. 3), problem: (B1) Books Exchange (easy version), Accepted, #, Copy
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
 
#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f2(i,n) for(int i=2;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>0;j--)
#define ll long long int
#define next cout<<endl
 
using namespace std;
 
 
int max(int a,int b)
{
    int ans = (a>=b)?a:b;
    return ans;
}
 
int min(int a,int b)
{
    int ans = (a<=b)?a:b;
    return ans;
}
 
int main()
{
	int t;
	cin>>t;
	int ans=0;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<int> res(n,1);
		int ini,fini,cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			ini = i;
			fini = a[i];
			ans=0;
			while(ini != fini)
			{
				fini = a[fini];
				ans++;
			}
			res[i-1] =ans+1;
		}
		for(int i=0;i<n;i++)
		cout<<res[i]<<" ";
		next;		
	}
	return 0;
}
