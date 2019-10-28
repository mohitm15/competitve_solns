/**
 *    author:  mohitm
 *    created: 28.10.2019 17:25:21       
**/

//codechef October Lunchtime 2019 : Problem 1


#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int v[n];
        f0(i,n) cin>>v[i];    
        sort(v,v+n);
        int p=n/4;
        int x=v[p],y=v[2*p],z=v[3*p];
        int cntx=0,cnty=0,cntz=0,cnta=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<x)
            cntx++;
            else if(v[i]>=x && v[i]<y)
            cnty++;
            else if(v[i]>=y && v[i]<z)
            cntz++;
            else if(v[i]>=z)
            cnta++;
        }
        if((cntx==p)&&(cnty==p)&&(cntz==p)&&(cnta==p))
        cout<<x<<" "<<y<<" "<<z<<endl;
        else
        {
            cout<<"-1"<<endl;
        }
         
    }
    return 0;
}
    
