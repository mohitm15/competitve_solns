// contest: Codeforces Round #612 (Div. 2), problem: (A) Angry Students, Happy New Year!, #
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
 
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
 
 
int maxi(int a,int b)
{
    int y;
    if(a>=b)
    y=a;
    else
    y=b;
    return y;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<char> v(n);
        f0(i,n)
        cin>>v[i];
        int cnt=0,ans=-1;
        int firstA=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]=='A')
            {
                firstA=i;
                break;
            }
        }
        //cout<<"F = "<<firstA<<endl;
        vector<int> as(n,-1);
        int ind=0;
        for(int i=firstA;i<n;i++)
        {
            if(v[i]=='P')
            {
                cnt++;
            }
            else if(v[i]=='A')
            {
                //as[ind++]=cnt;
                cnt=0;
            }
            as[ind++]=cnt;
            //cout<<"cnt = "<<cnt<<endl;
        }
        //int *i1;
        // f0(i,n)
        // {
        //     cout<<as[i]<<" ";
        // }
        //next;
        ans = *max_element(as.begin(),as.end());
        int pcnt=0;
        f0(i,n)
        {
            if(v[i]=='P')
            pcnt++;
        }
        if((ans == -1)||(pcnt==n))
        cout<<"0"<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}
