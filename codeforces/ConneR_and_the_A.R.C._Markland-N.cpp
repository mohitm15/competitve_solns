// contest: Codeforces Round #614 (Div. 2), problem: (A) ConneR and the A.R.C. Markland-N, Accepted, #
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
	while(t--)
    {
		unordered_set<int> us;
		int n,s,k,a;
		cin>>n>>s>>k;
		while(k--)
        {
			cin>>a;
			us.insert(a);
		}
		f0(i,n)
        {
			if(us.find(s+i)==us.end() && s+i<=n)
                { cout<<i<<"\n"; break;}
			if(us.find(s-i)==us.end() && s-i>0)
                { cout<<i<<"\n"; break;}
		}
	}
}
