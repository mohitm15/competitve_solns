// contest: Codeforces Round #604 (Div. 2), problem: (B) Beautiful Numbers, Happy New Year!, #
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
#define f2(i,n) for(int i=1;i<n;i++)
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
	cin >> t;
	while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> p(n);
        f0(i,n) {
        cin>>a[i];
        p[a[i]-1]=i;
        }
 
        int mx = 0;
        int mn = n;
        for(int i=0;i<n;i++)
        {
            mx = max(p[i],mx);
            mn = min(p[i],mn);
            if((mx-mn)==i)
            cout<<1;
            else
            {
            cout<<0;
            }
        }
        next;
	}	
	return 0;
}
