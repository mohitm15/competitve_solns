// Codechef January Long Challenge 2020 : Problem 3
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
        ll n,m;
        cin>>n>>m;
        ll a[n][m];
        f0(i,n)
        f0(j,m)
        cin>>a[i][j];
        ll ans = n*m;
        
        for(ll i=1;i<(n-1);i++)
        {   
            for(ll j=1;j<(m-1);j++)
            {
                ll k=1;
                while((i-k>=0) && (i+k<=n-1)&& (j-k>=0) && (j+k<=m-1))
                {
                    if((a[i][j-k]==a[i][j+k]) && (a[i-k][j]==a[i+k][j]))
                        ans++;
                    else
                        break;
                    k++;
                }
            }
        }
        cout<<ans<<endl;
	}
    return 0;	
}
