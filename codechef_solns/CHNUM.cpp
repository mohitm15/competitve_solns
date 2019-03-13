//March Long Challenge 2019-Problem 1
//By Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    long n,cnt1=0,cnt2=0;
    std::cin >> n;
    long a[n];
    for(int i=0;i<n;i++)
    std::cin >> a[i];
    for(int i=0;i<n;i++)
    {
      if(a[i]>=0)
      {
        cnt1++;
      }
      else if(a[i]<0)
      {
        cnt2++;
      }
    }
    if(cnt1==0)
    cnt1=cnt2;
    else if(cnt2==0)
    cnt2=cnt1;
    if (cnt1>=cnt2)
    std::cout << cnt1 <<" "<<cnt2 << '\n';
    else
      std::cout << cnt2 <<" "<<cnt1 << '\n';
  }
  return 0;
}
