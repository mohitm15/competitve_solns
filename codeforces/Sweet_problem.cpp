// contest: Codeforces Round #603 (Div. 2), problem: (A) Sweet Problem, Happy New Year!, #
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
#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int r,g,b,ans=0;
        cin>>r>>g>>b;
        if(r>=(g+b))
        ans=g+b;
        else if(g>=(r+b))
        ans=r+b;
        else if(b>=(g+r))
        ans = g+r;
        else
        {
            // if((r-g)>0)
            // {
            //     ans = ans + r-g;
            //     r = g;
            // }
            // else
            // {
            //     ans = ans + g-r;
            //     g = r;
            // }
            // cout<<"r ="<<r<<" g="<<g<<"b ="<<b<<"ans ="<<ans<<endl;
            // if((g-b)>0)
            // {
            //     ans = ans + g-b;
            //     g = b;
            // }
            // else
            // {
            //     ans = ans + b-g;
            //     b = g;
            // }
            // cout<<"r ="<<r<<" g="<<g<<"b ="<<b<<"ans ="<<ans<<endl;
            // if(r==1)
            // ans+=1;
            // else if(r>=2)
            // {
            //     while(r>=2)
            //     {
            //         ans+=3;
            //         r=r-2;
            //         g=g-2;
            //         b=b-2;
            //     }
            // }
            // cout<<"r ="<<r<<" g="<<g<<"b ="<<b<<"ans ="<<ans<<endl;
            ans = floor((r+g+b)/2);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}
