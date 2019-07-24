// Codechef April-Lunchtime 2019 : Problem 1
// By Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ull unsigned long long int
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ull n;
        cin>>n;
        string f[n],l[n];
        int cnt[n]={0};
        f(i,n)
        {
            cin>>f[i]>>l[i];
        }
        f(i,n)
        {
            for(int j=i+1;j<n;j++)
            {
                if(f[i]==f[j])
                {
                    cnt[j]++;
                    cnt[i]++;
                    //cout<<l[j]<<"--";
                }
            }
            //cout<<'\n';
            if(cnt[i]>0)     
            cout<<f[i]<<" "<<l[i]<<endl;
            else
            cout<<f[i]<<endl;
        }
    }
    return 0;
}
