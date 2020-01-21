// contest: Codeforces Round #614 (Div. 2), problem: (C) NEKO's Maze Game, Accepted, #
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
	vector<vector<int>> v;
	int n,q;
	cin>>n>>q;
	v.resize(2,vector<int>(n,0));
	int ans=0;
	while(q--)
	{
		int r,c;
		cin>>r>>c;
		r--,c--;
		int yo=(v[r][c]==0)?1:-1;
		v[r][c]=1-v[r][c];
		for(int i=-1;i<=1;i++)
		{
			if(c+i<0 || c+i>=n)
				continue;
			if(v[1-r][c+i]==1)
				ans+=yo;
		}
		cout<<((ans==0)?"Yes\n":"No\n");
	}
}
