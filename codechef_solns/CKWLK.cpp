/**
 *    author:  mohitm
 *    created: 21.10.2019 07:14:16       
**/

#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    ll n,cnt1=0,cnt2=0,ncopy;
    cin>>n;
    ncopy=n;
    while(ncopy%10==0)
    {
        ncopy=ncopy/10;
        cnt1++;
    }
    while(ncopy%2 == 0)
    {
        ncopy=ncopy/2;
        cnt2++;
    }
    if(cnt1>=cnt2 && ncopy==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    }
    return 0;
}
