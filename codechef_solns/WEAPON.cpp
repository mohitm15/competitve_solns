//Codechef November Challenge 2019: Problem 1
//By MOhit Maroliya

//SOLN 1

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
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> s(n);
        f0(i,n) cin>>s[i];
        int ans=0;
        for(int j=0;j<10;j++)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(s[i][j]=='1')
                cnt++;
            }
            if(cnt%2==1)
            ans+=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}


//SOLN 2

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
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> s(n);
        f0(i,n) cin>>s[i];
        char res[10];
        f0(i,10)
        res[i]=(int)s[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if((res[j]=='1' && s[i][j]=='1') ||(s[i][j]=='0' && res[j]=='0'))
                res[j]='0';
                else
                res[j]='1';
            }
            // for(int k=0;k<10;k++)
            // cout<<res[k];
            // next;
        }
        int cnt=0;
        f0(l,10)
        {
            if(res[l]=='1')
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
