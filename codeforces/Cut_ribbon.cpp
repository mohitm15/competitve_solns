//SOln By Mohit Maroliya


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n;
    int a,b,c;
    int x,y,z;

    //cout<<"Enter the length of ribbon"<<endl;
    cin>>n;

    //cout<<"Enter the 3 values of lengths allowed"<<endl;
    cin>>a>>b>>c;

    //array to memoize values
    vector<int> dp(n+1);

    //initialize
    dp[0]=0;

    for(i=1;i<=n;i++)
    {
        x=y=z=-1;

        if(i>=a)
            x=dp[i-a];

        if(i>=b)
            y=dp[i-b];

        if(i>=c)
            z=dp[i-c];

        if(x==-1 && y==-1 && z==-1)
            dp[i]=-1;

        else
            dp[i]=max(max(x,y),z)+1;
    }

    if(dp[n]==-1)
        cout<<"Not possible";

    else
        cout<<dp[n];

    cout<<endl;

    return 0;
}
