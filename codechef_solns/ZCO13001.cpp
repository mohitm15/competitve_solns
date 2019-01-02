#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
  long long int n;
  cin>>n;
  long long int a[n];
  long long int sum[n];
  long long int totalsum=0;
  for(long long int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for(long long int i=0;i<n;i++)
  {
    totalsum+=a[i];
  }
  for(long long int i=0;i<n;i++)
  {
    sum[i]=totalsum-a[i];
    totalsum-=a[i];
  }
  long long int ans=0;
  for(long long int i=0;i<n;i++)
  {
    ans+=abs((a[i]*(n-i-1))-sum[i]);
  }
  cout<<ans;
  return 0;
  }
