//SOLN BY MOHIT MAROLIYA


#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define pii pair<int,int>

int n,t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>t,
        cout<<((t%3==0 || t%7==0 || (t%7)%3==0 || (t%3==1 && t>6)|| (t%3==2 && t>12) )?"YES\n":"NO\n");
    }
    return 0;
}
