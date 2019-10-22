/**
 *    author:  mohit
 *    created: 21.10.2019 06:28:16       
**/

#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector<int> v(n);
    f0(i,n) cin>>v[i];
    vector<int> v1;
    v1=v;
    sort(v.begin(),v.end());
    int high = v[n-1],low=v[0];
    vector<int> res;
    f0(i,n)
        {
        if((high == v1[i])||(low ==v1[i]) )
        res.push_back(v1[i]);
        }
    for(int i=0;i<2;i++)
        {   
        cout<<res[i]<<" ";
        }
    next;
    }
    return 0;
}
