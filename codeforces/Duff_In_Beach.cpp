/* 
 SOLUTIONS BY MOHIT MAROLIYA
 */
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int lim=1e6+10;
long long m,n;
long long l;
int f[lim];
int g[lim];
long long shengxia;
int need[lim];
vector<long long>sum[lim],sigma[lim];
long long duan;

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>m>>l>>n;
    for(int i=1;i<=m;i++)
    {
        //cin>>f[i];
        scanf("%d",&f[i]);
    }
    shengxia = l%m;
    for(int i=1;i<=shengxia;i++)
        g[i]=f[i];
    sort(f+1,f+m+1);
    sort(g+1,g+shengxia+1);
    for(int i=1;i<=m;i++)
    {
        need[i-1]=upper_bound(f+1,f+m+1,f[i])-f-2;
    }
    long long pre = l/m;
    long long duan=min((long long)n,(long long)pre+(l%m==0?0:1));
    //cout<<duan<<" "<<shengxia<<" "<<pre<<endl;
    for(int i=0;i<duan;i++)
    {
        int len = i+1;
        for(int j=0;j<m;j++)
        {
            if(len==1)
                sum[len].push_back(1);
            else
                sum[len].push_back(sigma[len-1][need[j]]%mod);
//cout<<"sum["<<len<<"]["<<sum[len].size()-1<<"]="<<sum[len][sum[len].size()-1]<<endl;
            if(j==0)
                sigma[len].push_back(sum[len][j]%mod);
            else
                sigma[len].push_back((sigma[len][j-1]+sum[len][j])%mod);

        }
    }
    long long ans=0;

    for(int i=1;i<=duan&&i<=pre;i++)
        for(int j=0;j<m;j++)
        {
//cout<<" A="<<pre-i+1<<" i="<<i<<" num="<<sum[i][j]<<endl;
                int value=f[i];
                ans=((long long)ans+(long long)(((pre-i+1)%mod)*sum[i][j]%mod))%mod;
//cout<<ans<<endl;
        }
    if(shengxia!=0)
    {
        ans=(ans+shengxia)%mod;
//cout<<"ans="<<ans<<endl;
        for(int i=1;i<=duan-1 && i<=pre;i++)
        {
            for(int j=1;j<=shengxia;j++)
            {
                int value=g[j];
                int pos=upper_bound(f+1,f+m+1,value)-f-2;
//cout<<"pos="<<pos<<endl;
//cout<<g[j]<<" "<<f[pos+1]<<endl;
//cout<<"simga["<<i<<"]["<<pos<<"]="<<sigma[i][pos]<<endl;
//cout<<"value="<<value<<" pos="<<pos<<" sigma="<<sigma[i][pos-1]<<endl;
                ans=((long long)ans+(long long)(sigma[i][pos]))%mod;
//cout<<"i="<<i<<" ans="<<ans<<endl;
            }
        }
    }
    cout<<ans%mod<<endl;
}
