// ICPC Asia-Gwalior- Pune Onsite Replay Contest 2019 : Problem 2

// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#include<bits/stdc++.h>
using namespace std;

int maxi(int a,int b)
{
    int ans ;
    ans=(a>=b)?a:b;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;cin>>n;
        int a[n];
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            sum+=a[i];
        }
        int q;cin>>q;
        int quer[q];
        int max=0;
        for(int i=0;i<q;i++) 
        {
            cin>>quer[i];
            max = maxi(quer[i],max);
        }
        //cout<<"max = "<<max<<endl;
        for(int i=n+1;i<=max;i++)
        {
            sum += a[i-1]-a[i-n];
           // cout<<"a[i-1] = "<<a[i-1]<<"  a[i-n] ="<<a[i-n]<<endl;
            //cout<<"sum = "<<sum<<endl;
            a[i] = floor(sum/n );
        }
        // for(int i=1;i<=max;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
        for(int i=0;i<q;i++)
        {
            cout<<a[quer[i]]<<endl;
        }
    }
    return 0;
}
