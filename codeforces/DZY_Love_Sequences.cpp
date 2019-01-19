//SOLN BY MOHIT MAROLIYA
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int a[100001],dp[100001];
int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        dp[i]=1;
        if (a[i]>a[i-1])
            dp[i]=dp[i-1]+1;
        ans=max(ans,min(dp[i]+1,n));
    }
    for (i=1;i<=n;i++)
    {
        if (i-dp[i]-1>0&&a[i-dp[i]+1]-1>a[i-dp[i]-1])
            ans=max(ans,dp[i]+dp[i-dp[i]-1]+1);
        if (i-dp[i]>0&&a[i-dp[i]+2]-1>a[i-dp[i]])
            ans=max(ans,dp[i]+dp[i-dp[i]]);
    }
    printf("%d",ans);
    return 0;
}
