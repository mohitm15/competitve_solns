//Feb Long Challenge 2019- Problem 03
//By Mohit MAroliya


#include<bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    long long a[n],d[n],left,right,res=-1;
    for(int i=0;i<n;i++)
      std::cin >> a[i];
      for(int i=0;i<n;i++)
        std::cin >> d[i];
    for(int i=0;i<n;i++)
    {
      if(i==0)
      {
        left=a[n-1];
        right=a[1];
        // ld=d[n-1];
        // rd=d[1];
      }
      else if(i==(n-1))
      {
        left=a[n-2];
        right=a[0];
        // ld=d[n-2];
        // rd=d[0];
      }
      else
      {
        left=a[i-1];
        right=a[i+1];
        // ld=d[i-1];
        // rd=d[i+1];
      }
      if((left >= d[i])||(right >= d[i])||((right+left)>= d[i]))
      {
        if(res<0)
         res= -1;
      }
      else
      {
        if(res<d[i])
        res=d[i];
      }
      //std::cout << "res["<<i<<"]"<<res << '\n';
    }
    std::cout << res << '\n';
  }
  return 0;
}
