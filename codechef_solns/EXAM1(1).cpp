// June Cook-Off 2019: Problem 1

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
    int t;cin>>t;
    while(t--)
    {int n,ans=0;cin>>n;
      char a[n],b[n];
      f(i,n){cin>>a[i];}
      f(i,n){cin>>b[i];}
      f(i,n)
      {if(a[i]==b[i]) ans++;
     else if(b[i]=='N')ans+=0;
      else if(a[i]!=b[i])
      {if(i!=(n-1)) i++;
     else {/* do nothing */}}}
      cout<<ans<<'\n';}
      return 0;
}
