// contest: Codeforces Round #609 (Div. 2), problem: (B) Modulo Equality, Accepted, #
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> acopy(n);
	f0(i,n)
	cin>>a[i];
	f0(i,n)
	cin>>b[i];
	sort(b.begin(),b.end());
	//sort(a.begin(),a.end());
	int x,ans=m;
	f0(i,n)
	{
		x=(b[i]+m-a[0])%m;
		f0(j,n)
		acopy[j]=(a[j]+x)%m;
		sort(acopy.begin(),acopy.end());
		if(acopy == b)
		ans = min(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}
