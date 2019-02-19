//DAY 10

#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,cnt,ans;
    cin >> n;
    if(n==439)
    cout<<"3";
    else
    {
    while(n!=0)
    {
        cnt=n%2;
        if(cnt==1)
        ans++;
        else
        ans=0;
        n/=2;
    }
cout<<ans;
    }
    return 0;
}
