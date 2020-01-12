// Codechef Januaury Long Challenge 2020 : Problem 2

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
        int n;
        cin>>n;
        ll k =pow(10,n);
        ll a,s,b,c,d,e;
        cin>>a;
        s = 2*k+a;
        cout<<s<<endl;
        cin>>b;
        c = k - b;
        cout<<c<<endl;
        cin>>d;
        e = k - d;
        cout<<e<<endl;
        int check;
        cin>>check;
        if(check==-1)
        return 0;
	}
    return 0;	
}
