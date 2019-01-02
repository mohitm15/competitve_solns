#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    long long a[n],i,j;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long count=0;
    for(i=0,j=1;i<n;)
    {
        if(abs(a[i]-a[j])>=k)
        {
            count+=(n-j);
            i++;
        }
        else
            j++;
    }
    cout<<count;
    return(0);
}
