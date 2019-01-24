// SOLN BY MOHIT MAROLIYA
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,d,k;
cin>>n>>d;
int arr[101];
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
}
sort(arr+1,arr+n+1);
int ans=0;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if(arr[j]-arr[i]<=d && j-i+1>ans){
            ans = j-i+1;
        }
    }
}
    cout<<n-ans<<endl;
return 0;
}
