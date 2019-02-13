//Feb Long Challenge 2019- Problem 04
//By Mohit Maroliya


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n,i,sum=0;
        cin>>n;
        long int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        
        
        cout<<sum-n+1<<endl;
    }
    return 0;
}
