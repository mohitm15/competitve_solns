//CodeChef November Challenge 2019 : Problem 2
//By Mohit Maroliya

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
        vector<int> v(n);
        for(int i=2;i<n;i++)
        {
            v[0]=0;v[1]=0;
            vector<int>::iterator ip;
            ip=find(v.begin(),v.end(),v[i-1]);
            //cout<<(ip-v.begin());
            if(ip-v.begin()==(i-1))
            v[i]=0;
            else
            {
                for(int j=(ip-v.begin());j<(i-1);j++)
                {

                    if(v[j]==v[i-1])
                    v[i]=i-j-1;
                }    
            }      
        }
        int cnt=0;
        f0(i,n)
        {
            if(v[i]==v[n-1])
            cnt++;
        }
        // f0(i,n)
        // cout<<v[i]<<" ";
        // next;
        cout<<cnt<<endl;
    }
    return 0;
}
