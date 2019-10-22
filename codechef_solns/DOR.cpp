/**
 *    author:  mohitm
 *    created: 21.10.2019 17:58:25       
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
        ll l,r;
        cin>>l>>r;
        
        ll maxi=0,cnt=0,p=1,no;
        no =l^r;
        while(no)
        {
            cnt++;
            no>>=1;
        }
        while(cnt--)
        {
            maxi+=p;
            p<<=1;
        }
        maxi=maxi|r;
        cout<<maxi<<endl;
    }
    return 0;
}
