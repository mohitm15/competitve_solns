//contest: Codeforces Round #536 (Div. 2), problem: (C) Lunar New Year and Number Division, Pretests passed, #
 
 
#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long  n;
  std::cin >> n;
  long long  a[n];
  for(long long i=0;i<n;i++)
  std::cin >> a[i];
  sort(a,a+n);
  long long cnt=0;
  for(long long i=0;i<(n/2);i++)
  {
    cnt+=((a[i]+a[n-i-1])*(a[i]+a[n-i-1]));
    //std::cout << "cnt=" << cnt <<'\n';
  }
  std::cout << cnt << '\n';
  return 0;
}
